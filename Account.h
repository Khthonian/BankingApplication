#pragma once
#include <vector>
#include <string>
#include "Transaction.h"

class Account {
// Establish virtual functions
public:
    virtual double deposit(double deposit, double balance) = 0;
    virtual double withdraw(double withdraw, double balance) = 0;
protected:
    double balance; // balance
    std::vector<Transaction> history; // history
};