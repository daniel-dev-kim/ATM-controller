#pragma once
#include <unordered_map>
#include "Account.h"

class BankAPI {
    std::unordered_map<int, int> pinDatabase; // cardNumber -> PIN
    std::unordered_map<int, std::vector<Account>> accounts; // cardNumber -> accounts

public:

    void addCard(int cardNumber, int pin, int initBalance)
    {
        pinDatabase[cardNumber] = pin;
        accounts[cardNumber].emplace_back(initBalance);
    }

    void addAccount(int cardNumber, int initBalance)
    {
        if (!accounts.count(cardNumber)) throw std::runtime_error("Card number not found.");
        accounts[cardNumber].emplace_back(initBalance);
    }

    bool validatePIN(int cardNumber, int pin) {
        return pinDatabase.count(cardNumber) && pinDatabase[cardNumber] == pin;
    }

    std::vector<Account>& getAccounts(int cardNumber) {
        if (!accounts.count(cardNumber)) throw std::runtime_error("Card number not found.");
        return accounts[cardNumber];
    }
};
