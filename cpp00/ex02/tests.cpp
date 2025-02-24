#include "Account.hpp"
#include <iostream>

int main() {

    // Display global accounts info (expect all zero at startup)
    Account::displayAccountsInfos();
    std::cout << std::endl;

    // Create a few accounts
    Account a(42);
    Account b(54);
    Account c(957);

    // Display global after creation
    Account::displayAccountsInfos();
    std::cout << std::endl;

    // Do some deposits and withdrawals
    a.makeDeposit(5);
    a.makeWithdrawal(20);
    b.makeDeposit(100);
    b.makeWithdrawal(2);
    c.makeDeposit(765);
    c.makeWithdrawal(1000); // Might get refused if c has less
    std::cout << std::endl;

    // Display all accounts globally
    Account::displayAccountsInfos();
    std::cout << std::endl;

    // Also display individual statuses
    a.displayStatus();
    b.displayStatus();
    c.displayStatus();

    // When main() ends, destructors will be called automatically
    return 0;
}
