#include "Savings.h"

double Savings::computeInterest(double balance, int years)
{
	// Calculate interest for savings account or isa account
	double interest;
	double innerEquation = (1 + (0.0085 / 12));
	interest = balance * pow(innerEquation, (12 * years));	
	return interest;
}

void Savings::deposit(double deposit)
{
	balance = balance + deposit;
	std::cout << "New balance: " << balance << endl;
}

void Savings::withdraw(double withdraw)
{
	verified = verifyTransfer(withdraw);
	if (verified == true)
	{
		balance = balance - withdraw;
		cout << "New balance: " << balance << endl;
	}
	else {
		cout << "Attempted withdrawal exceeds account balance" << endl;
	}
}

bool Savings::verifyTransfer(double transfer)
{
	bool verified;
	limitCheck = balance - transfer;
	if (limitCheck >= limit) {
		verified = true;
	}
	else {
		verified = false;
	}
	return verified;
}