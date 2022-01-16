#pragma once
#include "Account.h"

class Checking : 	public Account {
private:
	static const float m_MinimumBalance;

public:
	using Account::Account;  // Inherited constructors so that I don't have to rewrite it just to call the base class version
	//Checking(const std::string &name, float balance);
	~Checking();
	void Withdraw(float amount) override;
	float GetMinimumBalance() const;
};

