#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double intRate)
    : Account {name, balance}, intRate{intRate} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool SavingsAccount::deposit(double amount) {
    amount += amount * (intRate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.intRate << "%]";
    return os;
}
