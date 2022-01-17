#include "stdafx.h"
#include "gtest/gtest.h"
#include <thread>
#include <future>

/*
* Create a joinable thread, cause it to execute, and verify that the thread function squared a value.
* This also shows one way to get the data from the thread by using std::ref to allow the change to
* be visible in the main thread.
*/
TEST(TestConcurrencySupport, TestJoinableWithArgument) {

  // First test the lambad function to ensure it works as designed
  auto square = [](double& value) -> void { value *= value; };
  double value = 5.0;
  square(value);
  EXPECT_EQ(25.0, value);

  // Create the thread and verify that it is a joinable thread
  value = 5;
  auto squareThread = std::thread(square, std::ref(value));
  EXPECT_TRUE(squareThread.joinable());

  // Ensure that the thread finishes prior to checking the value
  squareThread.join();
  EXPECT_EQ(25.0, value);
}

/*
* Create a task using std::async, cause it to execute, and verify that the thread function squared a value.
* This also shows another way to get the data from the thread by using the future object returned to get the result.
* The test of the result won't happen until the thread is finished and the future.get() method returns.
*/
TEST(TestConcurrencySupport, TestAsynchFuture) {
  // First test the lambad function to ensure it works as designed
  auto square = [](double value) -> double { return value * value; };
  double value = 5.0;
  auto result = square(value);
  EXPECT_EQ(25.0, result);

  // Create the thread and verify that it is a joinable thread
  value = 12;
  auto asyncResult = std::async(std::launch::async, square, value);

  // Since the policy was asynch the function might have already finished by the time get() is called
  EXPECT_TRUE(asyncResult.valid());
  EXPECT_EQ(144.0, asyncResult.get());
}

/*
* Create a task using std::async, cause it to execute, and verify that the thread function squared a value.
* This also shows another way to get the data from the thread by using the future object returned to get the result.
* The test of the result won't happen until the thread is finished and the future.get() method returns.
*/
TEST(TestConcurrencySupport, TestAsynchFutureDeferred) {
  // First test the lambad function to ensure it works as designed
  auto square = [](double value) -> double { return value * value; };

  // Create the thread and verify that it is a joinable thread
  double value = 12;
  auto asyncResult = std::async(std::launch::deferred, square, value);

  // Since the policy was deferred the function won't execute until the get() is called
  EXPECT_TRUE(asyncResult.valid());
  EXPECT_EQ(144.0, asyncResult.get());
  EXPECT_FALSE(asyncResult.valid());
}

/*
* Create a task using std::async, cause it to execute, and verify that the thread function squared a value.
* This also shows another way to get the data from the thread by using the future object returned to get the result.
* The test of the result won't happen until the thread is finished and the future.get() method returns.
*/
TEST(TestConcurrencySupport, TestAsynchPromiseFuture) {
  // First test the lambad function to ensure it works as designed
  auto square = [](std::promise<double> &input) -> double 
  { 
    auto value = input.get_future().get();
    return value * value; 
  };

  // Create the thread and verify that it is a joinable thread
  std::promise<double> input;
  auto asyncResult = std::async(std::launch::async, square, std::ref(input));
  input.set_value(10);

  // Since the policy was deferred the function won't execute until the get() is called
  EXPECT_TRUE(asyncResult.valid());
  EXPECT_EQ(100.0, asyncResult.get());
  EXPECT_FALSE(asyncResult.valid());
}