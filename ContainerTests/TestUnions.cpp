#include "stdafx.h"
#include "gtest/gtest.h"

TEST(TestUnions, TestSizeOfUnion) {

  union test {
    char a;
    int x;
    double y;
  };

  test value{ 'a' };

  EXPECT_EQ(sizeof(double), sizeof(test));
  EXPECT_EQ(value.a, 'a');
  EXPECT_EQ(value.x, 97);
  // EXPECT_EQ(value.y, 97.0); undefined 

  value.y = 25.0;
  EXPECT_EQ(value.y, 25.0);  // no good way to know how this might be represented as an int or a char
}