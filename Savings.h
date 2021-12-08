#pragma once
#include <vector>
#include "Account.h"
#include "InterestEarning.h"

class Savings : public Account, public InterestEarning {
public:
	double interestRate;
private:	
	bool isa;
};
