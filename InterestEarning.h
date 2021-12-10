#pragma once
#include <string>

class InterestEarning {
public:
	virtual double computeInterest(double balance, int years) = 0;
};