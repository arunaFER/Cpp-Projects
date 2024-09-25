/*
Checking Account is a type of Account

Withdraw - Has a flat withdrawal fee

*/

#ifndef _CheckingAccount_H_
#define _CheckingAccount_H_

#include "Account.h"

#include <string>

class CheckingAccount: public Account{
    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
private:
    static constexpr const char *defName = "Unnamed Checking Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defWithdrawalFee = 1.5;
protected:
    double withdrawalFee;
public:
    CheckingAccount(std::string name = defName, double balance = defBalance, double withdrawalFee = defWithdrawalFee);
    bool withdraw(double amount);
};

#endif