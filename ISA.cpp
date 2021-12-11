#include "ISA.h"

double ISA::computeInterest(double balance, int years)
{
	double interest;
	double innerEquation = (1 + (0.0115 / 12));
	interest = balance * pow(innerEquation, (12 * years));
	return interest;
}

void ISA::deposit(double deposit)
{
	balance = balance + deposit;
	cout << "New balance: " << balance << endl;
}

void ISA::withdraw(double withdraw)
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

bool ISA::verifyTransfer(double transfer)
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
