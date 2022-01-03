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