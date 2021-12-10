#pragma once
#include "Account.h"

class Current : public Account {
private:
    double overdraft = 500;
public:
    Current() {}
    Current(string x) {
        balance = std::stod(x);
        std::cout << "Current account created!" << std::endl;
    }
    ~Current() {
        std::cout << "Current account closed!" << std::endl;
    }
    double deposit(double deposit, double balance);
    double withdraw(double withdraw, double balance);
};