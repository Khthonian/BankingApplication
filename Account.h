#pragma once
#include <vector>

class Account {
public:
    double balance; // balance
    std::vector<double> history; // history
    double deposit(double deposit, double balance);
    double withdraw(double withdraw, double balance);
    //std::string toString();
};