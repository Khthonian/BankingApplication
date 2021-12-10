#pragma once
#include<iostream>
#include <vector>
#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning {
private:
	double interestRate = 0;
public:
	Savings() {}
	Savings(string x) {
		balance = std::stod(x);
		std::cout << "Savings account created!" << std::endl;
	}
	~Savings() {
		std::cout << "Savings account closed!" << std::endl;
	}
	string accountName;
	double computeInterest(double balance, int years);
	double deposit(double deposit, double balance);
	double withdraw(double withdraw, double balance);
};
