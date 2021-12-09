#pragma once
#include<iostream>
#include <vector>
#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning {
private:
	double interestRate;
public:
	double computeInterest(double balance, int years);
};
