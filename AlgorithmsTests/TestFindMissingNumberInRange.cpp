#include "stdafx.h"
#include "TestFindMissingNumberInRange.h"

#include <vector>
#include <algorithm>
#include "Algorithms.h"



/// <summary>
/// Test with range from -1 through 4 but 1 of the 6 numbers is missing.
/// </summary>
TEST_F(TestFindMissingNumberInRange, TestFindMissingNumber)
{
  std::vector<int> values = { 3, 2, -1, 0, 4 };

  auto result = Algorithms::findMissingNumberInRange(values.begin(), values.end(), -1, 4);
  EXPECT_EQ(result, 1);
}

/// <summary>
/// Test with range from -1 through 4 but none of the 6 numbers is missing so 5 is returned.
/// </summary>
TEST_F(TestFindMissingNumberInRange, TestNoMissingNumberInRange)
{
  std::vector<int> values = { 3, 1, 2, -1, 0, 4 };

  auto result = Algorithms::findMissingNumberInRange(values.begin(), values.end(), -1, 4);
  EXPECT_EQ(result, 5);
}

