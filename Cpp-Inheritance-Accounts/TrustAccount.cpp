#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double intRate)
    : SavingsAccount {name, balance, intRate}, withdrawalCount{0}{
}

bool TrustAccount::deposit(double amount){
    if (amount >= bonusThreshold){
        amount += depositBonus;
    }

    return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount) {
    double maxWithdrawal = balance * maxWithdrawPercent;
    if (withdrawalCount >= maxWithdrawals || amount > maxWithdrawal)
        return false;
    
    ++withdrawalCount;
    return SavingsAccount::withdraw(amount);
}


std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.intRate << "%]";
    return os;
}