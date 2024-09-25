#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance, double withdrawalFee)
    : Account {name , balance}, withdrawalFee{withdrawalFee}{
};

// Withdraw:
//  Adds a $1.5 withdrawal fee
bool CheckingAccount::withdraw(double amount){
    double totalWithdrawal = amount + withdrawalFee;
    // if (balance - totalWithdrawal >=0) {
    //     balance -= totalWithdrawal;
    //     return true;
    // } else
    //     return false;
    return Account::withdraw(totalWithdrawal);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.withdrawalFee << "]";
    return os;
}
