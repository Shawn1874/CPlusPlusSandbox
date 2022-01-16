#include "stdafx.h"
#include "gtest/gtest.h"
#include "Checking.h"
#include <memory>

TEST(TestCheckingAccount, TestConstructor) {
  const auto initialBalance = 350.0f;
  auto checking = std::make_unique<Checking>("Rick Henderson", initialBalance);
  EXPECT_EQ(initialBalance, checking->GetBalance());
  EXPECT_EQ(50.0, checking->GetMinimumBalance());
  EXPECT_EQ(std::string("Rick Henderson"), checking->GetName());
}

/*
* Verifies that a checking account can be used via the Account type, and the correct behavior
* of the Withdraw method.
*/
TEST(TestCheckingAccount, TestWithdraw) {
  const auto initialBalance = 255550.0f;
  //auto checking = std::make_unique<Checking>("Ricky Bobby", initialBalance);
  std::unique_ptr<Account> checking{ new Checking("Ricky Bobby", initialBalance) };
  EXPECT_EQ(initialBalance, checking->GetBalance());
  checking->Withdraw(550.0f);
  EXPECT_EQ(255000.0f, checking->GetBalance());

  // test min balance
  EXPECT_THROW(checking->Withdraw(255000.0f), std::runtime_error);
}

TEST(TestCheckingAccount, TestDeposit) {
  const auto initialBalance = 7500.0f;
  //auto checking = std::make_unique<Checking>("Ricky Bobby", initialBalance);
  std::unique_ptr<Account> checking{ new Checking("Bob Walton", initialBalance) };
  EXPECT_EQ(initialBalance, checking->GetBalance());
  checking->Deposit(400.0f);
  EXPECT_EQ(initialBalance + 400.0f, checking->GetBalance());
}