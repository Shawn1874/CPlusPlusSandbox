#pragma once
#include <memory>
#include <string>
class Account;

class AccountsFactory
{

public:
   AccountsFactory::AccountsFactory();
   std::unique_ptr<Account> buildSavingsAccount(std::string name, float balance, float rate);
   std::unique_ptr<Account> buildCheckingAccount(std::string name, float balance);
   
private:
   std::unique_ptr<Account> savings;
   std::unique_ptr<Account> checking;
};

