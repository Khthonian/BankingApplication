#include "Savings.h"

double Savings::computeInterest(double balance, int years)
{
	// Calculate interest for savings account or isa account
	double interest;
	double innerEquation = (1 + (0.0085 / 12));
	interest = balance * pow(innerEquation, (12 * years));	
	return interest;
}

double Savings::deposit(double deposit, double balance)
{
	balance = balance + deposit;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}

double Savings::withdraw(double withdraw, double balance)
{
	balance = balance - withdraw;
	std::cout << "Current balance: " << balance << std::endl;
	return balance;
}
