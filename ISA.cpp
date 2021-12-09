#include "ISA.h"

double ISA::computeInterest(double balance, int years)
{
	double interest;
	double innerEquation = (1 + (0.0115 / 12));
	interest = balance * pow(innerEquation, (12 * years));
	return interest;
}
