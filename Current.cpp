#include <iostream>
#include "Current.h"

void Current::deposit(double deposit) {
	balance = balance + deposit;
	std::cout << "New balance: " << balance << endl;
	
}

void Current::withdraw(double withdraw) {
	verified = verifyTransfer(withdraw);
	if (verified == true)
	{
		balance = balance - withdraw;
		std::cout << "New balance: " << balance << endl;
	}
	else {
		std::cout << "Attempted withdrawal exceeds account overdraft of 500" << endl;
	}
}

bool Current::verifyTransfer(double transfer)
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
