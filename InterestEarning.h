#pragma once
#include <string>

class InterestEarning {
public:
	virtual double computeInterest(bool isa, double balance, int years) = 0;
};