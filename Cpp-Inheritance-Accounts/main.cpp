

#include <iostream>
#include <vector>

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
   
    // Accounts
    std::vector<Account> accounts;

    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);

    
    // Savings 
    std::vector<SavingsAccount> savAccounts;

    savAccounts.push_back(SavingsAccount {} );
    savAccounts.push_back(SavingsAccount {"Superman"} );
    savAccounts.push_back(SavingsAccount {"Batman", 2000} );
    savAccounts.push_back(SavingsAccount {"Wonderwoman", 5000, 5.0} );

    display(savAccounts);
    deposit(savAccounts, 1000);
    withdraw(savAccounts, 2000);


    // Checking
    std::vector <CheckingAccount> checkAccounts;

    checkAccounts.push_back(CheckingAccount {});
    checkAccounts.push_back(CheckingAccount {"Tom", 3000});
    checkAccounts.push_back(CheckingAccount {"Ann", 2000});

    display(checkAccounts);
    deposit(checkAccounts, 1000);
    withdraw(checkAccounts, 3000);

    
    // Trust
    std::vector<TrustAccount> trustAccounts;
    trustAccounts.push_back(TrustAccount {} );
    trustAccounts.push_back(TrustAccount {"Athos", 10000, 5.0} );
    trustAccounts.push_back(TrustAccount {"Porthos", 20000, 4.0} );
    trustAccounts.push_back(TrustAccount {"Aramis", 30000} );

    display(trustAccounts);
    deposit(trustAccounts, 1000);
    withdraw(trustAccounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trustAccounts, 1000);

    return 0;
}

