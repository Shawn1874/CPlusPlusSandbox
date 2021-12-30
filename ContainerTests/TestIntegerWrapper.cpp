#include "stdafx.h"
#include "gtest/gtest.h"
#include "Integer.h"

TEST(TestIntegerWrapper, TestDefaultConstructor) {
  Integer value;
  EXPECT_EQ(value.GetValue(), 0);
}

TEST(TestIntegerWrapper, TestParameterizedConstructor) {
  Integer value(5);
  EXPECT_EQ(value.GetValue(), 5);
}

TEST(TestIntegerWrapper, TestCopyConstructor) {
  Integer value(5);
  Integer copiedValue(value);
  EXPECT_EQ(value.GetValue(), copiedValue.GetValue());
}

TEST(TestIntegerWrapper, TestCopyAssignment) {
  Integer value(15);
  Integer copiedValue;
  EXPECT_EQ(copiedValue.GetValue(), 0);
  EXPECT_EQ(value.GetValue(), 15);

  copiedValue = value;
  EXPECT_EQ(value.GetValue(), copiedValue.GetValue());
}

TEST(TestIntegerWrapper, TestIncrement) {
  Integer value(5);
  Integer originalValue = value++;
  EXPECT_EQ(value.GetValue(), 6);
  EXPECT_EQ(originalValue.GetValue(), 5);
}

TEST(TestIntegerWrapper, TestPreIncrement) {
  Integer value(5);
  Integer incremented =  ++value;
  EXPECT_EQ(value.GetValue(), 6);
  EXPECT_EQ(incremented.GetValue(), 6);
}

TEST(TestIntegerWrapper, TestComparison) {
  Integer first(5);
  Integer second(10);
  EXPECT_FALSE(first == second);
  EXPECT_TRUE(second == 10);  // 10 is implicitly cast into an Integer
  EXPECT_TRUE(10 == second);  // 10 is implicitly cast into an Integer
}
TEST(TestIntegerWrapper, TestAdditionMember) {
  Integer first(5);
  Integer second(10);
  EXPECT_EQ(first + second, 15);

  // Verify that second arg can be a primitive
  EXPECT_EQ(first + 20, 25);
  
  // Verify that first arg can be a primitive
  EXPECT_EQ(25, second + 15); 

  // Verify that operator+ did not mutate objects
  EXPECT_TRUE(second == 10);
  EXPECT_TRUE(first == 5);

}



