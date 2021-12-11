#pragma once
#include "Account.h"

class Current : public Account {
private:
    double limit = -500;
public:
    Current() {}
    Current(double x) {
        balance = (x);
        std::cout << "Current account created!" << std::endl;
    }
    ~Current() {
        std::cout << "Current account closed!" << std::endl;
    }
    void deposit(double deposit);
    void withdraw(double withdraw);
    bool verifyTransfer(double transfer);
};