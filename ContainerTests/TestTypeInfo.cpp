#include "stdafx.h"
#include "gtest/gtest.h"
#include "Checking.h"
#include "Savings.h"
#include <typeinfo>
#include <cmath>

/* 
* Notice the return type of the typeid operator
*/
TEST(TestTypeInfo, TestName) {
  Checking checkingAcct("test", 1000.0f);
  const std::type_info& ti = typeid(checkingAcct);
  EXPECT_EQ(std::string("class Checking"), ti.name());
}

/*
* Verifies that typeid can be invoked with a typename or with an expression
*/
TEST(TestTypeInfo, TestEquality) {
  Checking checkingAcct("test", 1000.0f);
  Savings savingsAcct("savings", 1500.0f, 0.2f);
  Savings savingsAcct2("savings2", 3200.0f, 0.3f);

  EXPECT_FALSE(typeid(Checking) == typeid(Savings));
  EXPECT_TRUE(typeid(savingsAcct) == typeid(savingsAcct2));
}

/*
* Verifies that typeid can be invoked with pointer types
*/
TEST(TestTypeInfo, TestEqualityPointers) {
  auto checkingAcct = std::make_unique<Checking>("test", 1000.0f);
  auto savings = std::make_unique<Savings>("savings", 1500.0f, 0.2f);
  auto savings2 = std::make_unique<Savings>("savings2", 3200.0f, 0.3f);

  EXPECT_FALSE(typeid(checkingAcct) == typeid(savings));
  EXPECT_TRUE(typeid(savings) == typeid(savings2));
  EXPECT_TRUE(typeid(savings) == typeid(std::unique_ptr<Savings>));
}

/*
* Verifies that downcast is possible if the type is compatible or a nullptr is returned
*/
TEST(TestTypeInfo, TestDynamicCastPointer)
{
  Account* account = new Savings("savings", 1500.0f, 0.2f);
  Savings* savings = dynamic_cast<Savings*>(account);
  EXPECT_FALSE(nullptr == savings);  // should not be null

  Account* checkingAcct = new Checking("test", 1000.0f);
  Savings* savings2 = dynamic_cast<Savings*>(checkingAcct);
  EXPECT_TRUE(nullptr == savings2);
}

/*
* Verifies that dynamic_cast works with references, but a failure results in std::bad_cast exception
*/
TEST(TestTypeInfo, TestDynamicCastReference)
{
  Savings savingsAcct("savings", 1500.0f, 0.2f);
  Account &account = savingsAcct;
  EXPECT_NO_THROW(Savings savingsAcctRef = dynamic_cast<Savings&>(account));
  EXPECT_THROW(Account &checkingAcct = dynamic_cast<Checking&>(account), std::bad_cast);
}

/*
* Verifies that downcasting can be done with static_cast, but it is not the best way to perform a downcast. It will
* not detect incompatible types which will result in undefined behavior.
*/
TEST(TestTypeInfo, TestStaticCast)
{
  Account* account = new Savings("savings", 1500.0f, 0.2f);
  Savings* savings = static_cast<Savings*>(account);
  EXPECT_FALSE(nullptr == savings);  // should not be null

  // The problem is that a Savings and Checking object are different tyeps but static_cast still returned a non-null
  // pointer.  So what is a savings2 in this case?
  Account* checkingAcct = new Checking("test", 1000.0f);
  Savings* savings2 = static_cast<Savings*>(checkingAcct);
  EXPECT_FALSE(nullptr == savings2);
}

/*
* Test new C++11 fixed width types
*/
TEST(TestTypeInfo, TestFixedWidthTypes)
{
#ifdef _M_X64
   EXPECT_EQ(sizeof(uintptr_t), 8);
   EXPECT_EQ(sizeof(uint64_t), 8);
#else
   EXPECT_EQ(sizeof(uintptr_t), 4);
   EXPECT_EQ(sizeof(uint64_t), 8);
#endif
}

struct TestPoint {
   double x;
   double y;
   char* name;
   int foo;
};

TEST(TestTypeInfo, TestDefaultInitialization)
{
   double value{};
   int number{};
   TestPoint p1{};
   EXPECT_EQ(0.0, value);
   EXPECT_EQ(0, number);
   EXPECT_EQ(0.0, p1.x);
   EXPECT_EQ(0.0, p1.y);
   EXPECT_EQ(nullptr, p1.name);
   EXPECT_EQ(0, p1.foo);
}

TEST(TestTypeInfo, TestRoundFloat)
{
   double value = floor((double) atof("1024.50000125012")); // *1000.0) / 1000.0;
   EXPECT_EQ(1024.5, value);

}