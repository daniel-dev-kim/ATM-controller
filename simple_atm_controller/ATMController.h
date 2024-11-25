#pragma once
#include <iostream>

#include "Bank.h"

class ATMController {
    BankAPI& bankAPI;
    int currentCard;
    std::vector<Account>* selectedAccounts;
    Account* currentAccount;

public:
    ATMController(BankAPI& api) : bankAPI(api), currentCard(-1), selectedAccounts(nullptr), currentAccount(nullptr) {}

    void insertCard(int cardNumber) {
        currentCard = cardNumber;
        selectedAccounts = nullptr;
        currentAccount = nullptr;
        std::cout << "Card inserted: " << cardNumber << "\n";
    }

    bool enterPIN(int pin) {
        if (bankAPI.validatePIN(currentCard, pin)) {
            std::cout << "PIN validated.\n";
            selectedAccounts = &bankAPI.getAccounts(currentCard);
            return true;
        } else {
            std::cout << "Invalid PIN.\n";
            return false;
        }
    }

    void selectAccount(int accountIndex) {
        if (!selectedAccounts) throw std::runtime_error("No account available. PIN not validated?");
        if (accountIndex < 0 || accountIndex >= selectedAccounts->size())
            throw std::invalid_argument("Invalid account index.");
        currentAccount = &(*selectedAccounts)[accountIndex];
        std::cout << "Account selected: Index " << accountIndex << "\n";
    }

    void seeBalance() {
        if (!currentAccount) throw std::runtime_error("No account selected.");
        std::cout << "Current balance: $" << currentAccount->getBalance() << "\n";
    }

    void deposit(int amount) {
        if (!currentAccount) throw std::runtime_error("No account selected.");
        currentAccount->deposit(amount);
        std::cout << "Deposited: $" << amount << "\n";
    }

    void withdraw(int amount) {
        if (!currentAccount) throw std::runtime_error("No account selected.");
        currentAccount->withdraw(amount);
        std::cout << "Withdrew: $" << amount << "\n";
    }

    void rejectCard() {
        std::cout << "Card rejected.\n";
        currentCard = -1;
        selectedAccounts = nullptr;
        currentAccount = nullptr;
    }
};
