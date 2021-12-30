#include "stdafx.h"
#include "TestSmartPointers.h"
#include <memory>
#include "Integer.h"

TestSmartPointers::TestSmartPointers()
{
}


TestSmartPointers::~TestSmartPointers()
{
}

TEST_F(TestSmartPointers, TestUniquePtrRelease)
{
  auto p = std::make_unique<int>(0);
  *p = 5;

  EXPECT_NE(*p, NULL);
  EXPECT_EQ(*p, 5);

  auto temp = p.release();
  GTEST_ASSERT_NE(temp, nullptr);
  GTEST_ASSERT_EQ(p, nullptr);
}

TEST_F(TestSmartPointers, TestUniquePtrObservers)
{
  auto p = std::unique_ptr<Integer>(new Integer(5));
  EXPECT_TRUE(p);
  auto p2 = p.get();
  EXPECT_TRUE(p);
  EXPECT_TRUE(p2);
}

