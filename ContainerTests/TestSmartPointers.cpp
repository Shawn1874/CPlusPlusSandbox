#include "stdafx.h"
#include "TestSmartPointers.h"
#include <memory>
#include <vector>
#include "Integer.h"

TestSmartPointers::TestSmartPointers()
{
}

TestSmartPointers::~TestSmartPointers()
{
}

TEST_F(TestSmartPointers, TestUniquePtrRelease)
{
  auto p = std::make_unique<int>(0);  // make_unique is a method so () needed
  *p = 5;

  EXPECT_NE(*p, NULL);
  EXPECT_EQ(*p, 5);

  auto temp = p.release();
  GTEST_ASSERT_NE(temp, nullptr);
  GTEST_ASSERT_EQ(p, nullptr);
}

TEST_F(TestSmartPointers, TestEmptyUniquePtr)
{
    struct test {
        int x;
        int y;
    };

    std::unique_ptr<test> testPtr;

    EXPECT_EQ(testPtr, nullptr);

    EXPECT_EQ(testPtr.get(), nullptr);

    std::auto_ptr<test> testAutoPtr;

    EXPECT_FALSE(testAutoPtr.get());

}

TEST_F(TestSmartPointers, TestUniquePtrObservers)
{
  std::unique_ptr<Integer> p{ new Integer(5) };

  // Test operators
  EXPECT_TRUE(p);
  EXPECT_EQ(*p, 5);  // works because of the comparison operator of Integer class
  EXPECT_EQ( (*p).GetValue(), 5);  // *p returns a reference to the object
  EXPECT_EQ(p->GetValue(), 5);     // p-> returns pointer to the object

  // Test reset
  p.reset(new Integer{ 300 });
  EXPECT_EQ(*p, 300);  // works because of the comparison operator of Integer class
  EXPECT_EQ((*p).GetValue(), 300);  // *p returns a reference to the object
  EXPECT_EQ(p->GetValue(), 300);     // p-> returns pointer to the object

  // Test get
  auto p2 = p.get();
  EXPECT_TRUE(p);
  EXPECT_TRUE(p2);
  EXPECT_EQ(*p2, 300);
}

TEST_F(TestSmartPointers, TestSharedPtrUseCount)
{
  std::shared_ptr<Integer> p{ new Integer(5) };
  EXPECT_EQ(p.use_count(), 1);
  EXPECT_EQ(p.get()->GetValue(), 5);
}

TEST_F(TestSmartPointers, TestSharedPtrOfVector)
{
  std::shared_ptr<std::vector<int>> v{ new std::vector<int> {1, 2, 3, 4, 5} };
  EXPECT_EQ(v->size(), 5);
  v->push_back(6);
  EXPECT_EQ(v->at(5), 6);

  // how to use sub-script operator to get at elements
  EXPECT_EQ((*v)[5], 6);
}

TEST_F(TestSmartPointers, TestWeakPtrLock)
{
  std::weak_ptr<int> wk;

  {
    auto sp = std::make_shared<int>(5);
    wk = sp;
    EXPECT_EQ(5, *sp);
    EXPECT_EQ(1, sp.use_count());
    EXPECT_EQ(1, wk.use_count());
    EXPECT_FALSE(wk.expired());
    auto sp2 = wk.lock(); // increment use count and get a shared pointer
    EXPECT_EQ(5, *sp2);
    EXPECT_EQ(2, sp.use_count());
    EXPECT_EQ(2, wk.use_count());
  }

  EXPECT_TRUE(wk.expired());
}

