#include "stdafx.h"
#include "TestCustomAlgorithms.h"
#include "Algorithms.h"
#include <vector>
#include <deque>

TestCustomAlgorithms::TestCustomAlgorithms()
{
}


TestCustomAlgorithms::~TestCustomAlgorithms()
{
}

TEST_F(TestCustomAlgorithms, TestReverseString)
{
  std::string name = "nwahs";
  std::string result = "shawn";

  Algorithms::Reverse(name.begin(), name.end());

  EXPECT_EQ(name, result);

}

TEST_F(TestCustomAlgorithms, TestReverseVector)
{
  std::vector<int> original = { 9, 7, 5, 3, 1 };
  std::vector<int> expected = { 1, 3, 5, 7, 9 };

  Algorithms::Reverse(original.begin(), original.end());

  EXPECT_EQ(original, expected);

}

TEST_F(TestCustomAlgorithms, TestAdd) {
  EXPECT_EQ(20, Algorithms::add(15, 5));
  EXPECT_EQ(20, Algorithms::add(5, 15));

  EXPECT_EQ(20.0, Algorithms::add(15.2, 4.8));
  EXPECT_EQ(20.0, Algorithms::add(4.8, 15.2));

  EXPECT_EQ('b', Algorithms::add('a', static_cast<char>(1)));
}

TEST_F(TestCustomAlgorithms, TestSum)
{
  std::vector<int> original = { 9, 7, 5, 3, 1 };

  EXPECT_EQ(25, Algorithms::sum(&original[0], original.size()));

  std::vector<char> characters{ ' ', '!', '(' }; // 32 + 33 + 40 = 105 ('i')
  EXPECT_EQ('i', Algorithms::sum(&characters[0], characters.size()));
}

TEST_F(TestCustomAlgorithms, TestMinMax)
{
  std::vector<int> original = { 9, 2, 5, 15, 3, 1 };

  auto result = Algorithms::minMax(&original[0], original.size());
  EXPECT_EQ(1, result.first);
  EXPECT_EQ(15, result.second);

  std::vector<char> characters{ 'z', 'a', 'w', 'T', 'c', 'L' };
  result = Algorithms::minMax(&characters[0], characters.size());
  EXPECT_EQ('L', result.first);
  EXPECT_EQ('z', result.second);
}


TEST_F(TestCustomAlgorithms, TestMergeSortedVectors)
{
  std::vector<int> a = { 0, 1, 7, 11, 0, 0, 0, 0};
  std::vector<int> b = { 2, 3, 9, 12 };

  Algorithms::MergeSortedRanges(std::begin(b), std::end(b), std::begin(a), std::begin(a) + 4);
  EXPECT_EQ(a[2], 2);
  EXPECT_EQ(a[3], 3);
  EXPECT_EQ(a[5], 9);
  EXPECT_EQ(a[7], 12);
  EXPECT_EQ(a.size(), 8);


  std::deque<int> c = { 1, 1, 7, 11, 0, 0, 0, 0 };
  std::deque<int> d = { 2, 3, 9, 12 };

  Algorithms::MergeSortedRanges(d.begin(), d.end(), c.begin(), c.begin() + 4);
  EXPECT_EQ(c[0], 1);
  EXPECT_EQ(c[1], 1);
  EXPECT_EQ(c[2], 2);
  EXPECT_EQ(c[3], 3);
  EXPECT_EQ(c[4], 7);
  EXPECT_EQ(c[5], 9);
  EXPECT_EQ(c[6], 11);
  EXPECT_EQ(c[7], 12);
  EXPECT_EQ(c.size(), 8);

  EXPECT_EQ(d[0], 2);
  EXPECT_EQ(d[1], 3);
  EXPECT_EQ(d[2], 9);
  EXPECT_EQ(d[3], 12);
}

TEST_F(TestCustomAlgorithms, TestMergeSortedDeques)
{

  std::deque<int> c = { 1, 1, 7, 11, 0, 0, 0, 0 };
  std::deque<int> d = { 2, 3, 9, 12 };

  Algorithms::MergeSortedRanges(d.begin(), d.end(), c.begin(), c.begin() + 4);
  EXPECT_EQ(c[0], 1);
  EXPECT_EQ(c[1], 1);
  EXPECT_EQ(c[2], 2);
  EXPECT_EQ(c[3], 3);
  EXPECT_EQ(c[4], 7);
  EXPECT_EQ(c[5], 9);
  EXPECT_EQ(c[6], 11);
  EXPECT_EQ(c[7], 12);
  EXPECT_EQ(c.size(), 8);

  EXPECT_EQ(d[0], 2);
  EXPECT_EQ(d[1], 3);
  EXPECT_EQ(d[2], 9);
  EXPECT_EQ(d[3], 12);
}

TEST_F(TestCustomAlgorithms, TestFactorial)
{
  int  value{ 0 }, result{ 0 };
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 0);

  value = 1; 
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 1);

  value = 2;
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 2);

  value = 3;
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 6);

  value = 5; // 5 * 4 * 3 * 2 * 1 = 120
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 120);

  value = 7; // 5 * 4 * 3 * 2 * 1 = 120
  Algorithms::factorial(value, &result);
  EXPECT_EQ(result, 5040);
}
