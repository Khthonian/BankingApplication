#pragma once
#include <iostream>
#include "Savings.h"

class ISA : public Savings {
private:
	double limit = 0;
public:
	ISA() {}
	ISA(double x) {
		balance = (x);
		std::cout << "ISA account created!" << std::endl;
	}
	~ISA() {
		std::cout << "ISA account closed!" << std::endl;
	}
	double computeInterest(double balance, int years);
	void deposit(double deposit);
	void withdraw(double withdraw);
	bool verifyTransfer(double transfer);
};