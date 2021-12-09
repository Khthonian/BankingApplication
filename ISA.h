#pragma once
#include <iostream>
#include "Savings.h"

class ISA : public Savings {
public:
	double computeInterest(double balance, int years);
};
