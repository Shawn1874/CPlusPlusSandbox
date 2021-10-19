#include "stdafx.h"
#include "TestLamdas.h"
#include <vector>
TEST_F(TestLamdas, CaptureIdentifierByValueTest)
{
  int x(0), y(1);

  std::vector<int> values = { 1, 2, 3, 4, 5 };

  // test capturing by value
  std::for_each(values.begin(), values.end(), [x, y](int element) mutable {
    x += element;
    y *= element;
  });

  // Since captured by value neither was modified
  EXPECT_EQ(x, 0);
  EXPECT_EQ(y, 1);
}

TEST_F(TestLamdas, CaptureIdentifierByReferenceTest)
{
  int x(0), y(1);

  std::vector<int> values = { 1, 2, 3, 4, 5 };

  // test capturing by value
  std::for_each(values.begin(), values.end(), [&x, &y](int element) mutable {
    x += element;
    y *= element;
    });

  // Since captured by reference modifications within the lambda function are retained. 
  EXPECT_EQ(x, 15);
  EXPECT_EQ(y, 120);

}

TEST_F(TestLamdas, CaptureAllByReferenceTest)
{
  int x(0), y(1);

  std::vector<int> values = { 1, 2, 3, 4, 5 };

  // test capturing by value
  std::for_each(values.begin(), values.end(), [&](int element) mutable {
    x += element;
    y *= element;
    });

  // Since captured by reference modifications within the lambda function are retained. 
  EXPECT_EQ(x, 15);
  EXPECT_EQ(y, 120);
}

TEST_F(TestLamdas, CaptureAllByValueTest) 
{
  const int x(5);

  std::vector<int> values = { 1, 2, 3, 4, 5 };

  // test capturing x by value
  std::for_each(values.begin(), values.end(), [=](int& element) mutable {
    element += x;
    });

  EXPECT_EQ(6, values[0]);
  EXPECT_EQ(7, values[1]);
  EXPECT_EQ(10, values[4]);
}
