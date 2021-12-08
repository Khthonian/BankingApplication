// BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include "Current.h"
#include "Savings.h"

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	// you may also want to store a collection of opened accounts here
	std::vector<Current> currentAccounts;
	std::vector<Savings> savingsAccounts;
	bool isaOn = false;

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

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
			if (parameters[1] == "1") {
				std::cout << "New current account created";
			}
			else if (parameters[1] == "2") {
				std::cout << "New savings account created";
			}
			else if (parameters[1] == "3") {
				std::cout << "New ISA account created";
			}
			else {
				std::cout << "Invalid entry";
			}
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
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

