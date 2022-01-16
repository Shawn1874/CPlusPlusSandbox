#include "Checking.h"

#include <iostream>

const float Checking::m_MinimumBalance = 50.0;

//Checking::Checking(const std::string &name, float balance) :
//Account(name, balance) {
//}


Checking::~Checking() {
}

void Checking::Withdraw(float amount) {

	/*
	Balance should be greater than 0 & the amount
	to withdraw should be less than balance
	*/
	if ((m_Balance - amount) < Checking::m_MinimumBalance) {
		throw std::runtime_error("Insufficient balance");
	}
	else {
		Account::Withdraw(amount);
	}
}

float Checking::GetMinimumBalance() const {
	return Checking::m_MinimumBalance;
}
