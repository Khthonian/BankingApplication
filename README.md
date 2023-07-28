# Banking Application

This C++ program represents a simple banking application that allows users to perform various banking operations, such as opening different types of accounts, viewing account details, making deposits and withdrawals, transferring funds between accounts, projecting balance forward in time, and more.

## Getting Started

1. Clone or download this repository to your local machine.

2. Compile the C++ program using your preferred C++ compiler.

3. Run the compiled program in your terminal or command prompt.

## Usage

The application provides the following commands:

1. `open [type] [initial_deposit]`: Open a new account. Available account types: current(1), savings(2), isa(3).

2. `view [code]`: View account balance and recent transactions. Optionally, provide an account code to view a specific account.

3. `deposit [sum]`: Deposit funds into the last viewed account.

4. `withdraw [sum]`: Withdraw funds from the last viewed account.

5. `transfer [source] [destination] [sum]`: Transfer funds between accounts.

6. `project [years]`: Project balance forward in time, calculating compound interest.

7. `exit`: Exit the application.

## Notes

- The program supports multiple account types: Current, Savings, and ISA (Individual Savings Account).

- Accounts can be opened with an initial deposit, and the user can view transactions and balances.

- The application handles various input validations and provides feedback on actions performed.

- The interest calculation for the ISA and Savings accounts is based on compound interest over time.
