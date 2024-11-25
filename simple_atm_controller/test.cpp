#include "ATMController.h"
// --- Test Code ---
void runTests() {
    BankAPI bankAPI;
    ATMController atm(bankAPI);
    try {
        // Card 1 - one account
        bankAPI.addCard(12345678, 0000, 0);
        // Card 2 - two account
        bankAPI.addCard(23456789, 3333, 500);
        bankAPI.addAccount(23456789, 200);

        // Card 1 test
        atm.insertCard(12345678);
        if (!atm.enterPIN(0000)) throw std::runtime_error("Failed PIN validation.");
        atm.selectAccount(0);
        atm.seeBalance();
        atm.deposit(300);
        atm.seeBalance();
        atm.withdraw(200);
        atm.seeBalance();
        atm.rejectCard();

        // Card 2 test
        atm.insertCard(23456789);
        if (!atm.enterPIN(3333)) throw std::runtime_error("Failed PIN validation.");
        atm.selectAccount(0);
        atm.seeBalance();
        atm.deposit(1500);
        atm.seeBalance();
        atm.withdraw(500);
        atm.seeBalance();
        atm.selectAccount(1);
        atm.seeBalance();
        atm.withdraw(200);
        atm.seeBalance();
        atm.rejectCard();
    }

    catch (const std::exception& ex) {
        std::cerr << "Test failed: " << ex.what() << "\n";
        atm.rejectCard();
    }
}

int main() {
    runTests();
    return 0;
}