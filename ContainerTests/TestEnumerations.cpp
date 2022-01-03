#include "stdafx.h"
#include "gtest/gtest.h"

TEST(TestEnumerations, TestEnumValues) {
  enum color { RED, YELLOW, GREEN = 3, BLUE };
  EXPECT_EQ(RED, 0); // first value default is 0 unless assigned
  EXPECT_EQ(YELLOW, 1); // Subsequented elements have value equal to the previous value incremented
  EXPECT_EQ(GREEN, 3);  // 3 was manually asigned so value is not simply incremented to 2 in this case
  EXPECT_EQ(BLUE, 4);
}

TEST(TestEnumerations, TestStaticCast) {
  enum color { RED, YELLOW, GREEN = 3, BLUE };

  color colorValue = static_cast<color>(3);  // warning expected because it is an unscoped enum
  EXPECT_EQ(colorValue, color::GREEN);

  // This compiles but it is undefined behavior since 7 is out of range.  The compiler does not check that the value
  // is one of the defined values of the enum.
  colorValue = static_cast<color>(7);
  EXPECT_EQ(colorValue, 7);
}


TEST(TestEnumerations, TestScopedEnum) {
  // use of hte class keyword makes this a scoped enum so the values are not in the global namespace
  enum class color { RED, YELLOW, GREEN = 3, BLUE };

  EXPECT_EQ(color::RED, static_cast<color>(0));
  EXPECT_EQ(color::GREEN, static_cast<color>(3));
  EXPECT_EQ(color::BLUE, static_cast<color>(4));
}