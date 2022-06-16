#include "AccountsFactory.h"
#include "Checking.h"
#include "Savings.h"

AccountsFactory::AccountsFactory()
{
   savings = std::make_unique<Savings>("Rick Scott", 2000.0f, 0.2f);
   checking = std::make_unique<Checking>("Rick Scott", 2000.0f);
}

std::unique_ptr<Account> AccountsFactory::buildSavingsAccount(std::string name, float balance, float rate)
{
   return std::make_unique<Savings>(name, balance, rate);
}

std::unique_ptr<Account> AccountsFactory::buildCheckingAccount(std::string name, float balance)
{
   return std::make_unique<Checking>(name, balance);
}
