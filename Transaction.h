#pragma once
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Transaction {
public:
	string description;
	int sender;
	int sendee;
	Transaction() {}
	Transaction(int a, string x, double y, char* z) {
		sender = a;
		type = x;
		amount = y;
		time = z;
	}
	Transaction(int a, int b, string x, double y, char* z) {
		sender = a;
		sendee = b;
		type = x;
		amount = y;
		time = z;
	}
private:
	string type;
	char* time;
	double amount;
};