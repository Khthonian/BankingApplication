#pragma once
#include "Account.h"

class Current : public Account {
private:
    double overdraft = 500;
public:
    Current() {
        std::cout << "Current account created!" << std::endl;
    }
};