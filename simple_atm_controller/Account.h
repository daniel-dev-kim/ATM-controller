#pragma once
#include <stdexcept>

class Account {
public:
    int balance;

    Account(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) {
        if (amount <= 0) throw std::invalid_argument("Deposit amount must be positive.");
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= 0) throw std::invalid_argument("Withdraw amount must be positive.");
        if (amount > balance) throw std::runtime_error("Insufficient funds.");
        balance -= amount;
    }

    int getBalance() const {
        return balance;
    }
};