#include <iostream>
#include "Current.h"

double Current::deposit(double deposit, double balance) {
	balance = balance + deposit;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}

double Current::withdraw(double withdraw, double balance) {
	balance = balance - withdraw;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}
