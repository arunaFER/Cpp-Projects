/*
Trust Account is a type of Savings Account

Deposite:
    deposits of $5000.00 or more will receive a $50.00 bonus

Withdraw:
    withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance
*/

#ifndef _TrustAccount_H_
#define _TrustAccount_H_

#include "SavingsAccount.h"

#include <string>

class TrustAccount: public SavingsAccount{
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);
private:
    static constexpr const char *defName = "Unnamed Trust Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
    static constexpr double depositBonus = 50.0;
    static constexpr double bonusThreshold = 5000.0;
    static constexpr int maxWithdrawals = 3;
    static constexpr double maxWithdrawPercent = 0.2;
protected:
    int withdrawalCount;
public:
    TrustAccount(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif