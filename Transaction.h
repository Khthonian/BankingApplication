#pragma once
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Transaction {
private:
	string description;
	char time;
	double amount;
};