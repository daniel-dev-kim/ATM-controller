# ATM Controller
This project implements a simple ATM controller in C++. It includes core ATM functionalities such as card insertion, PIN verification, account selection, balance inquiry, deposits, and withdrawals. While this implementation doesn't integrate with real hardware or a banking system, it simulates these interactions for testing and further extension.

## Features
Insert Card: Simulate inserting a card by providing a card number.   
PIN Validation: Validate the provided PIN using a mock banking API.   
Account Selection: Select from multiple accounts associated with a card.   
Balance Inquiry: Check the balance of the selected account.   
Deposit Money: Add a specified amount to the account.   
Withdraw Money: Subtract a specified amount from the account (if funds are sufficient).   
Eject Card: Reset the system for the next user.   

## Requirements
C++11 or later.   
Visual Studio 2022

## How to Build
##### 1. Clone the repository:

```bash
git clone https://github.com/daniel-dev-kim/ATM-controller
cd ATM-controller
```
##### 2.Open the solution file in Visual Studio:
Navigate to the cloned repository folder and open the ATM-controller.sln file in Visual Studio.

##### 3. Build the project:
In Visual Studio, go to the Build menu and select Build Solution or press Ctrl+Shift+B to build the project.

##### 4. Run the project:
Press Ctrl+F5 to run the program without debugging, or press F5 to run with debugging.

## Code Overview
##### Account Class: Handles account-related operations like deposits, withdrawals, and checking the balance.

##### Bank Class: Simulates interactions with a banking system, such as PIN validation and fetching account data.

##### ATMController Class: Manages the ATM workflow, interacting with the user and Bank to process requests.

##### Test Code: A set of operations (runTests function) is provided to test the main features of the ATM controller.
