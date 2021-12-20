// BankingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "Current.h"
#include "Savings.h"
#include "ISA.h"
#include "Transaction.h"

int main()
{
	vector <string> parameters;
	string userCommand;
	// you may also want to store a collection of opened accounts here
	vector<Account*> accounts;
	Account* lastViewedAccount[1];

	// store the transactions in a vector
	vector<Transaction*> transactions;

	// interest calculation vector
	vector<Savings*> interestVector;

	// store bools to see whether an account of such types exists
	bool currentOn = false;
	bool isaOn = false;

	// create a variable to store timestamps of actions
	char* timestamp;

	// fix decimals
	cout << std::setprecision(2) << std::fixed;

	// welcome the user and display options
	cout << "~~~ Welcome to LincBank! ~~~" << endl;
	cout << "1. open [type] [initial_deposit]: current(1), savings(2), isa(3)" << endl;
	cout << "2. view [code]: view balance and recent transactions" << endl;
	cout << "3. deposit [sum]: deposit funds into last viewed account" << endl;
	cout << "4. withdraw [sum]: withdraw funds from last viewed account" << endl;
	cout << "5. transfer [source] [destination] [sum]: transfer funds between accounts" << endl;
	cout << "6. project [years]: project balance forward in time" << endl;
	cout << "7. options: see these options again" << endl;
	cout << "8. exit" << endl;

	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		cout << endl << ">>> ";

		getline(cin, userCommand);
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
		string command = parameters[0];

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			cout << "~~~ Welcome to LincBank! ~~~" << endl;
			cout << "1. open [type] [initial_deposit]: current(1), savings(2), isa(3)" << endl;
			cout << "2. view [code]: view balance and recent transactions" << endl;
			cout << "3. deposit [sum]: deposit funds into last viewed account" << endl;
			cout << "4. withdraw [sum]: withdraw funds from last viewed account" << endl;
			cout << "5. transfer [source] [destination] [sum]: transfer funds between accounts" << endl;
			cout << "6. project [years]: project balance forward in time" << endl;
			cout << "7. options: see these options again" << endl;
			cout << "8. exit" << endl;
		}
		else if (command.compare("open") == 0)
		{
			double paycheck = stod(parameters[2]);
			int sender = accounts.size() + 1;
			ostringstream paycheckStream;
			paycheckStream << std::fixed << std::setprecision(2) << paycheck;
			string paycheckString = paycheckStream.str();
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			while (3 == parameters.size())
			{
				/* create new object, add to storage vector, 
				set new object as last viewed object, capture time of execution,
				create a new transaction, set transaction description using timestamp*/
				string oDescrip1 = "--initial deposit: ", oDescrip2 = " on ";
				if ((parameters[1] == "1") && (currentOn == false)) {
					Current* currentAccount = new Current(paycheck);
					currentOn = true;
					accounts.push_back(currentAccount);
					lastViewedAccount[0] = currentAccount;
					time_t realTime = time(0);
					timestamp = ctime(&realTime);
					Transaction* transaction = new Transaction(sender, "initial deposit", paycheck, timestamp);
					transaction->description = oDescrip1 + paycheckString + oDescrip2 + timestamp;
					transactions.push_back(transaction);
					break;
				}
				else if (parameters[1] == "2") {
					Savings* savingsAccount = new Savings(paycheck);
					accounts.push_back(savingsAccount);
					lastViewedAccount[0] = savingsAccount;
					time_t realTime = time(0);
					timestamp = ctime(&realTime);
					Transaction* transaction = new Transaction(sender, "initial deposit", paycheck, timestamp);
					transaction->description = oDescrip1 + paycheckString + oDescrip2 + timestamp;
					transactions.push_back(transaction);
					break;
				}
				else if ((parameters[1] == "3") && (isaOn == false)) {
					if (paycheck >= 1000) {
						ISA* isaAccount = new ISA(paycheck);
						isaOn = true;
						accounts.push_back(isaAccount);
						lastViewedAccount[0] = isaAccount;
						time_t realTime = time(0);
						timestamp = ctime(&realTime);
						Transaction* transaction = new Transaction(sender, "initial deposit", paycheck, timestamp);
						transaction->description = oDescrip1 + paycheckString + oDescrip2 + timestamp;
						transactions.push_back(transaction);
						break;
					}
					else {
						cout << "Initial ISA balance must be >= 1000" << endl;
						break;
					}
				}
				else {
					cout << "Account could not be made" << endl;
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
				int i = stoi(parameters[1]) - 1;
				if (i < accounts.size())
				{
					/* determine account type, display account and
					transactions, set as last viewed account*/
					if (dynamic_cast<Current*>(accounts[i]))
					{
						cout << "Current account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						lastViewedAccount[0] = accounts[i];
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}
					else if (dynamic_cast<Savings*>(accounts[i]) && !(dynamic_cast<ISA*>(accounts[i])))
					{
						cout << "Savings account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						lastViewedAccount[0] = accounts[i];
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}
					else if (dynamic_cast<ISA*>(accounts[i]))
					{
						cout << "ISA account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						lastViewedAccount[0] = accounts[i];
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}
				}
				else if (i >= accounts.size())
				{
					cout << "This account does not exist" << endl;
				}
			}
			else if (1 == parameters.size())
			{
				for (int i = 0; i < accounts.size(); i++)
				{
					// same as before but without setting last viewed account
					if (dynamic_cast<Current*>(accounts[i]))
					{
						cout << "Current account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}
					else if (dynamic_cast<Savings*>(accounts[i]) && !(dynamic_cast<ISA*>(accounts[i])))
					{
						cout << "Savings account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}
					else if (dynamic_cast<ISA*>(accounts[i]))
					{
						cout << "ISA account | " << "Account Code: " << i + 1 << " | Balance: " << accounts[i]->balance << endl;
						for (int k = 0; k < transactions.size(); k++)
						{
							if ((i + 1 == transactions[k]->sender) || (i + 1 == transactions[k]->sendee)) {
								cout << transactions[k]->description;
							}
						}
					}

				}
			}
			else {
				cout << "Invalid entry" << endl;
			}
		}
		// allow the user to deposit funds into their accounts
		else if (command.compare("deposit") == 0)
		{
			// change account balance, create transaction
			double paycheck = stod(parameters[1]);
			int sender = stoi(parameters[1]) - 1;
			ostringstream paycheckStream;
			paycheckStream << std::fixed << std::setprecision(2) << paycheck;
			string paycheckString = paycheckStream.str();
			if (2 == parameters.size())
			{
				string dDescrip1 = "--deposit: ", dDescrip2 = " on ";
				lastViewedAccount[0]->deposit(paycheck);
				time_t realTime = time(0);
				timestamp = ctime(&realTime);
				Transaction* transaction = new Transaction(sender, "deposit", paycheck, timestamp);
				transaction->description = dDescrip1 + paycheckString + dDescrip2 + timestamp;
				transactions.push_back(transaction);
			}
			else {
				cout << "Cannot make deposit" << endl;
			}
		}
		// allow the user to withdraw funds from their accounts
		else if (command.compare("withdraw") == 0)
		{
		// change account balance, create transaction	
		double paycheck = stod(parameters[1]);
			int sender = stoi(parameters[1]) - 1;
			ostringstream paycheckStream;
			paycheckStream << std::fixed << std::setprecision(2) << paycheck;
			string paycheckString = paycheckStream.str();
			if (2 == parameters.size())
			{
				string wDescrip1 = "--withdrawal: ", wDescrip2 = " on ";
				lastViewedAccount[0]->withdraw(paycheck);	
				time_t realTime = time(0);
				timestamp = ctime(&realTime);
				Transaction* transaction = new Transaction(sender, "withdraw", paycheck, timestamp);
				transaction->description = wDescrip1 + paycheckString + wDescrip2 + timestamp;
				transactions.push_back(transaction);
			}
			else {
				cout << "Cannot make withdrawal" << endl;
			}
		}
		// allow the user to transfer funds between accounts
		else if (command.compare("transfer") == 0)
		{
			double paycheck = stod(parameters[3]);
			ostringstream paycheckStream;
			paycheckStream << std::fixed << std::setprecision(2) << paycheck;
			string paycheckString = paycheckStream.str();
			int sender = stoi(parameters[1]) - 1;
			int sendee = stoi(parameters[2]) - 1;
			// change balances, create transaction
			if (4 == parameters.size())
			{
				if ((sender < accounts.size()) && (sendee < accounts.size()))
				{
					bool canSend = accounts[sender]->verifyTransfer(paycheck);
					if (canSend = true)
					{
						time_t realTime = time(0);
						timestamp = ctime(&realTime);
						string tDescrip1 = "--transfer from account ", tDescrip2 = " to account ", tDescrip3 = ": ", tDescrip4 = " on ";
						Transaction* transaction = new Transaction(sender, sendee, "transfer", paycheck, timestamp);
						transaction->description = tDescrip1 + parameters[1] + tDescrip2 + parameters[2] + tDescrip3 + paycheckString + tDescrip4 + timestamp;
						cout << transaction->description;
						transactions.push_back(transaction);
						accounts[sender]->balance = accounts[sender]->balance - paycheck;
						accounts[sendee]->balance = accounts[sendee]->balance + paycheck;
					}
					else {
						cout << "Transaction cannot be sent" << endl;
					}
				}
				else if ((sender >= accounts.size()) || (sendee >= accounts.size()))
				{
					cout << "One of these accounts does not exist. Reinsert transfer request." << endl;
				}
			}
			else {
				cout << "Cannot make this transfer" << endl;
			}
		}
		else if (command.compare("project") == 0)
		{
			double projection = 0;
			int time = stoi(parameters[1]);
			interestVector.clear();
			// compute compound interest t years into the future
			if (2 == parameters.size())
			{
				for (int i = 0; i < accounts.size(); i++)
				{
					double part = 0;
					if (dynamic_cast<ISA*>(accounts[i]))
					{
						part = static_cast<ISA*>(accounts[i])->computeInterest(accounts[i]->balance, time);
					}
					else if ((dynamic_cast<Savings*>(accounts[i])))
					{
						part = static_cast<Savings*>(accounts[i])->computeInterest(accounts[i]->balance, time);
					}
					projection = projection + part;
				}
				cout << "The interest value of your assets in " << time << " year(s) is: " << projection;
			} 
			else {
				cout << "Cannot make this projection" << endl;
			}
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	cout << "Press enter to quit...";
	getchar();
}