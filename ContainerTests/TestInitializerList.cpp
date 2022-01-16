#include "stdafx.h"
#include "gtest/gtest.h"

TEST(TestInitializerList, TestRangeBasedLoop) {
  auto sum = 0;

  for (auto value : { 2, 4, 6, 8, 10 }) {
    sum += value;
  }

  EXPECT_EQ(sum, 30);
}


TEST(TestInitializerList, TestFwdIteration) {
  auto sum = 0;
  std::initializer_list<int> values { 2, 4, 6, 8, 10 };
  auto current = values.begin();
  auto last = values.end();
  for (; current != last; ++current ) {
    sum += *current;
  }

  EXPECT_EQ(sum, 30);
}

TEST(TestInitializerList, TestCapacityMethods) {
  auto list = { 1, 2, 3, 5, 5 };
  EXPECT_EQ(list.size(), 5);
  EXPECT_FALSE(std::empty(list));
}

TEST(TestInitializerList, TestAuto)
{
  auto n = { 5 }; //initializer list
  EXPECT_EQ(1, n.size()); // if n was an int there would be no method to call!

  auto m = *n.begin();
  EXPECT_EQ(5, m);

  // auto m = (5);
  // m.size();  // wouldn't compile
}