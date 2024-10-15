#include "stdafx.h"
#include "gtest/gtest.h"

TEST(TestBuiltInLiterals, TestFloatingPoint) {
  EXPECT_EQ(10, 0xa);  // 0x is a literal used to define a hex value
  EXPECT_TRUE(true);  // boolean literal

}



//namespace uc {
  long double operator"" _mi(long double val) {
    return val * 1.6;
  }

  long double operator"" _mi(unsigned long long val) {
    return val * 1.6;
  }

//}

TEST(TestUserDefinedLiterals, TestMilesToKm) {
  EXPECT_EQ(1.6, 1.0_mi);

  EXPECT_EQ(1.6, 1_mi);
}