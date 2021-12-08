#include <iostream>
#include "Account.h"

double Account::deposit(double deposit, double balance) {
	balance = balance + deposit;
	std::cout << "Current balance: " << balance << std::endl;
	history.push_back(deposit);
	return balance;
}

double Account::withdraw(double withdraw, double balance) {
	balance = balance - withdraw;
	std::cout << "Current balance: " << balance << std::endl;
	history.push_back(-(withdraw));
	return balance;
}