#include "ISA.h"

double ISA::computeInterest(double balance, int years)
{
	double interest;
	double innerEquation = (1 + (0.0115 / 12));
	interest = balance * pow(innerEquation, (12 * years));
	return interest;
}

double ISA::deposit(double deposit, double balance)
{
	balance = balance + deposit;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}

double ISA::withdraw(double withdraw, double balance)
{
	balance = balance - withdraw;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}
