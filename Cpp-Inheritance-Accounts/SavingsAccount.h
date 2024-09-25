/*
Savings Account is a type of Account
  adds an interest rate

Withdraw - same as a regular account

Deposit:
     Amount supplied to deposit will be incremented by (amount * int_rate/100) 
     and then the updated amount will be deposited
*/

#ifndef _SavingsAccount_H_
#define _SavingsAccount_H_

#include "Account.h"

#include <string>

class SavingsAccount: public Account {
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
    static constexpr const char *defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
protected:
    double intRate;
public:
    SavingsAccount(std::string name = defName, double balance =defBalance, double int_rate = defIntRate);    
    bool deposit(double amount);
    // Inherits the Account::withdraw methods
};

#endif
