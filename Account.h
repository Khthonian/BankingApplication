#pragma once
#include <vector>
#include <string>

using namespace std;

class Account {
// Establish virtual functions
protected:
    double limitCheck;
    bool verified;
public:
    double balance;
    virtual void deposit(double deposit) = 0;
    virtual void withdraw(double withdraw) = 0;
    virtual bool verifyTransfer(double transfer) = 0;
};