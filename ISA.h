#pragma once
#include <iostream>
#include "Savings.h"

class ISA : public Savings {
public:
	ISA() {}
	ISA(string x) {
		balance = std::stod(x);
		std::cout << "ISA account created!" << std::endl;
	}
	~ISA() {
		std::cout << "ISA account closed!" << std::endl;
	}
	double computeInterest(double balance, int years);
	double deposit(double deposit, double balance);
	double withdraw(double withdraw, double balance);
};