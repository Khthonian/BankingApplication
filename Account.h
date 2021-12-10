#pragma once
#include <vector>
#include <string>
#include "Transaction.h"

class Account {
// Establish virtual functions
public:
    double balance;
    virtual double deposit(double deposit, double balance) = 0;
    virtual double withdraw(double withdraw, double balance) = 0;
protected:
    std::vector<Transaction> history; // history
};