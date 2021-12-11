#pragma once
#include<iostream>
#include <vector>
#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning {
private:
	double interestRate;
	double limit;
	double interest;
public:
	Savings() {}
	Savings(double x) {
		balance = (x);
		std::cout << "Savings account created!" << std::endl;
	}
	~Savings() {
		std::cout << "Savings account closed!" << std::endl;
	}
	double computeInterest(double balance, int years);
	void deposit(double deposit);
	void withdraw(double withdraw);
	bool verifyTransfer(double transfer);
};
