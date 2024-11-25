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

## Code Overview
##### Account Class: Handles account-related operations like deposits, withdrawals, and checking the balance.

##### Bank Class: Simulates interactions with a banking system, such as PIN validation and fetching account data.

##### ATMController Class: Manages the ATM workflow, interacting with the user and Bank to process requests.

##### Test Code: A set of operations (runTests function) is provided to test the main features of the ATM controller.
