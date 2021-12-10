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
	std::vector<Current*> currentAccounts;
	std::vector<Savings*> savingsAccounts;
	std::vector<ISA*> isaAccounts;

	// store bools to see whether an account of such types exists
	bool currentOn = false;
	bool isaOn = false;

	// welcome the user and display options
	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;
	std::cout << "1. open (parameters[1]) (initial_deposit): current(1), savings(2), isa(3)" << std::endl;
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
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			if (1 < parameters.size())
			{
				if ((parameters[1] == "1") && (currentOn == false)) {
					Current* currentAccount = new Current(parameters[2]);
					currentOn = true;
					std::cout << "New current account created" << std::endl;
					currentAccounts.push_back(currentAccount);
				}
				else if (parameters[1] == "2") {
					Savings* savingsAccount = new Savings(parameters[2]);
					std::cout << "New savings account created" << std::endl;
					savingsAccounts.push_back(savingsAccount);
				}
				else if ((parameters[1] == "3") && (isaOn == false)) {
					double valueCheck = std::stod(parameters[2]);
					if (valueCheck >= 1000) {
						ISA* isaAccount = new ISA(parameters[2]);
						isaOn = true;
						std::cout << "New ISA account created" << std::endl;
						isaAccounts.push_back(isaAccount);
					}
					else {
						std::cout << "Initial ISA balance must be >= 1000" << std::endl;
					}
				}
				else {
					std::cout << "Account could not be made" << std::endl;
				}
			}
			else {
				std::cout << "Invalid entry" << std::endl;
			}
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
			if (1 < parameters.size())
				if (parameters[1] == "1")
				{
					std::cout << "Current account | Balance: " << currentAccounts[0]->balance << std::endl;
				}
				else if (parameters[1] == "2") {
					for (int i = 0; i < savingsAccounts.size(); i++)
					{
						std::cout << "Savings account " << i + 1 << " | Balance: " << savingsAccounts[i]->balance << std::endl;
					}
				}
				else if (parameters[1] == "3") {
					std::cout << "ISA account | Balance: " << isaAccounts[0]->balance << std::endl;
				}
				else {
					std::cout << "Invalid entry" << std::endl;
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