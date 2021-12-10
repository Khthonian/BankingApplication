// BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include "Current.h"
#include "Savings.h"
#include "ISA.h"

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	// you may also want to store a collection of opened accounts here
	std::vector<Account*> accounts;
	Account* lastViewedAccount[1];

	// store bools to see whether an account of such types exists
	bool currentOn = false;
	bool isaOn = false;

	// welcome the user and display options
	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;
	std::cout << "1. open [type] [initial_deposit]: current(1), savings(2), isa(3)" << std::endl;
	std::cout << "2. view [code]: view balance and recent transactions" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "#VIEW ACCOUNTS BEFORE MAKING TRANSACTIONS TO KNOW WHICH ACCOUNTS TO USE#" << std::endl;
	std::cout << "deposit [sum]: deposit funds into last viewed account" << std::endl;
	std::cout << "withdraw [sum]: withdraw funds from last viewed account" << std::endl;
	std::cout << "x. exit" << std::endl;

	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";

		std::getline(std::cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;
			std::cout << "1. open [type] [initial_deposit]: current(1), savings(2), isa(3)" << std::endl;
			std::cout << "2. view [code]: view balance and recent transactions" << std::endl;
			std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
			std::cout << "#VIEW AN ACCOUNT BEFORE MAKING TRANSACTIONS TO KNOW WHICH ACCOUNTS TO USE#" << std::endl;
			std::cout << "deposit [sum]: deposit funds into last viewed account" << std::endl;
			std::cout << "withdraw [sum]: withdraw funds from last viewed account" << std::endl;
			std::cout << "x. exit" << std::endl;
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			while (3 == parameters.size())
			{
				if ((parameters[1] == "1") && (currentOn == false)) {
					Current* currentAccount = new Current(parameters[2]);
					currentOn = true;
					std::cout << "New current account created" << std::endl;
					accounts.push_back(currentAccount);
					lastViewedAccount[0] = currentAccount;
					break;
				}
				else if (parameters[1] == "2") {
					Savings* savingsAccount = new Savings(parameters[2]);
					std::cout << "New savings account created" << std::endl;
					accounts.push_back(savingsAccount);
					lastViewedAccount[0] = savingsAccount;
					break;
				}
				else if ((parameters[1] == "3") && (isaOn == false)) {
					double valueCheck = std::stod(parameters[2]);
					if (valueCheck >= 1000) {
						ISA* isaAccount = new ISA(parameters[2]);
						isaOn = true;
						std::cout << "New ISA account created" << std::endl;
						accounts.push_back(isaAccount);
						lastViewedAccount[0] = isaAccount;
						break;
					}
					else {
						std::cout << "Initial ISA balance must be >= 1000" << std::endl;
						break;
					}
				}
				else {
					std::cout << "Account could not be made" << std::endl;
					break;
				}
			}
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
			if (2 == parameters.size())
			{
				int i = std::stoi(parameters[1]) - 1;
				if (i < accounts.size())
				{
					if (dynamic_cast<Current*>(accounts[i]))
					{
						std::cout << "Current account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
						lastViewedAccount[0] = accounts[i];
					}
					else if (dynamic_cast<Savings*>(accounts[i]) && !(dynamic_cast<ISA*>(accounts[i])))
					{
						std::cout << "Savings account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
						lastViewedAccount[0] = accounts[i];
					}
					else if (dynamic_cast<ISA*>(accounts[i]))
					{
						std::cout << "ISA account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
						lastViewedAccount[0] = accounts[i];
					}
				}
				else if (i >= accounts.size())
				{
					std::cout << "This account does not exist" << std::endl;
				}
			}
			else if (1 == parameters.size())
			{
				for (int i = 0; i < accounts.size(); i++)
				{
					if (dynamic_cast<Current*>(accounts[i]))
					{
						std::cout << "Current account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
					}
					else if (dynamic_cast<Savings*>(accounts[i]) && !(dynamic_cast<ISA*>(accounts[i])))
					{
						std::cout << "Savings account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
					}
					else if (dynamic_cast<ISA*>(accounts[i]))
					{
						std::cout << "ISA account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << std::endl;
					}
				}
			}
			else {
				std::cout << "Invalid entry" << std::endl;
			}
		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
			// get the time of the transfer
			time_t realTime = time(0);
			char* currentTime = ctime(&realTime);
			std::cout << currentTime;

			// make the transfer instance

		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	std::cout << "Press enter to quit...";
	std::getchar();
}