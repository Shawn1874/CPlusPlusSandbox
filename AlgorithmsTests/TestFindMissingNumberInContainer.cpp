#include "stdafx.h"
#include "TestFindMissingNumberInContainer.h"

#include <vector>
#include <algorithm>
#include "Algorithms.h"

/// <summary>
/// This tests the scenario where the first missing item is the first element of the range
/// </summary>
TEST_F(TestFindMissingNumberInContainer, TestWithVectorBestCase)
{
  std::vector<int> values = { 1, 2, 3, 4, 5 };

  auto result = Algorithms::findMissingNumberInContainer(values);
  EXPECT_EQ(result, 0);
}

/// <summary>
/// This tests the scenario where something between 0 and n-1 is missing
/// </summary>
TEST_F(TestFindMissingNumberInContainer, TestWithVector)
{
  std::vector<int> values = { 0, 3, 2, 4, 5 };

  auto result = Algorithms::findMissingNumberInContainer(values);
  EXPECT_EQ(result, 1);
}

/// <summary>
/// According to the algorithm definition something is missing within the range 0..n which could be 0, but not n
/// That is because the method uses the size to determine what n is supposed to be.  Therefore worst case scenario
/// is when n - 1 is missing from the container.
/// </summary>
TEST_F(TestFindMissingNumberInContainer, TestWithVectorWorstCase)
{
  std::vector<int> values = { 1, 2, 0, 4 };

  auto result = Algorithms::findMissingNumberInContainer(values);
  EXPECT_EQ(result, 3);
}

