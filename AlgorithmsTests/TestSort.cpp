#include "gtest/gtest.h"
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "TestSort.h"
#include <functional>
TEST(TestSorting, StdSortAscending) {
  std::vector<int> values = { 7, 2, 1, 5, 3, 25, 6 };
  std::sort(values.begin(), values.end());
  EXPECT_EQ(values[0], 1);
  EXPECT_EQ(values[values.size() - 1], 25);
}

TEST(TestSorting, StdSortDescendingWithGreater) {
  std::vector<int> values = { 7, 2, 1, 5, 3, 25, 6 };
  std::sort(values.begin(), values.end(), std::greater<int>());
  EXPECT_EQ(values[0], 25);
  EXPECT_EQ(values[values.size() - 1], 1);
}

TEST(TestSorting, StdSortDescendingWithLambda) {

  // Use auto keyword to show that it can be like a generic and reused
  auto greaterThan = [](auto x, auto y)->bool {  // return type not needed but here for an example
    return x > y;
  };

  // first use the stored lambda
  std::vector<int> values = { 7, 2, 1, 5, 3, 25, 6 };
  std::sort(values.begin(), values.end(), greaterThan);
  EXPECT_EQ(values[0], 25);
  EXPECT_EQ(values[values.size() - 1], 1);

  // Now try with an embedded lambda
  std::sort(values.begin(), values.end(), [](int x, int y) -> bool { return x > y; });
  EXPECT_EQ(values[0], 25);
  EXPECT_EQ(values[values.size() - 1], 1);

  // first use the stored lambda
  std::vector<double> doubles = { 1.2, 0.3, 1.1 };
  std::sort(doubles.begin(), doubles.end(), greaterThan);
  EXPECT_EQ(doubles[0], 1.2);
  EXPECT_EQ(doubles[doubles.size() - 1], 0.3);
}

TestSort::TestSort()
{
}

TestSort::~TestSort()
{
}
