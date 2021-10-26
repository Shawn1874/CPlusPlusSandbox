#include "stdafx.h"
#include "gtest/gtest.h"
#include "algorithms.h"
#include <vector>
#include <deque>
#include <list>

TEST(TestBubbleSort, TestWithVector) {
  std::vector<int> values = { 5, 4, 7, 0, 2 };
  Algorithms::bubbleSort(values, [](auto first, auto second) {
    return first > second;
    });

  // run 1 produces 4 5 0 2 7
  // run 2 produces 4 0 2 5 7
  // run 3 produces 0 2 4 5 7


  EXPECT_EQ(0, values[0]);
  EXPECT_EQ(2, values[1]);
  EXPECT_EQ(4, values[2]);
  EXPECT_EQ(5, values[3]);
  EXPECT_EQ(7, values[4]);
}

TEST(TestBubbleSort, TestWithDeque) {
  std::deque<int> values = { 10, 5, 4, 7, 0, 2 };
  Algorithms::bubbleSort(values, [](auto first, auto second) {
    return first > second;
    });

  // run 1 produces 4 5 0 2 7
  // run 2 produces 4 0 2 5 7
  // run 3 produces 0 2 4 5 7


  EXPECT_EQ(0, values[0]);
  EXPECT_EQ(2, values[1]);
  EXPECT_EQ(4, values[2]);
  EXPECT_EQ(5, values[3]);
  EXPECT_EQ(7, values[4]);
}

// Challenge for some other day.  Write a version of bubble sort that uses only a forward iterator
//TEST(TestBubbleSort, TestWithList) {
//  std::list<int> values = { 5, 4, 7, 0, 2 };
//  std::list<int> sortedValues = { 0, 2, 4, 5, 7 };
//  Algorithms::bubbleSort(values, [](auto first, auto second) {
//    return first > second;
//    });
//
//  // run 1 produces 4 5 0 2 7
//  // run 2 produces 4 0 2 5 7
//  // run 3 produces 0 2 4 5 7
//
//
//  EXPECT_EQ(sortedValues, values);
//}