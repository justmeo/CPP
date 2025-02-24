#include "Account.hpp"
#include <iostream>
#include <ctime>

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor: create an account with an initial deposit
Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructor: called automatically when the object goes out of scope
Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// Return the total number of existing accounts
int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

// Return the overall total amount of money across all accounts
int Account::getTotalAmount( void )
{
    return _totalAmount;
}

// Return how many deposits have been made across all accounts
int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

// Return how many withdrawals have been made across all accounts
int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

// Display global info about all accounts
void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

// Make a deposit and update static and member counters
void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// Attempt to withdraw an amount; if not enough balance, refuse
bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

// For quickly checking the amount (in real life, might do more checks)
int Account::checkAmount( void ) const
{
    return _amount;
}

// Display info about this specific account
void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

// Timestamp is displayed before each log message.
// The exact format used by 42's official tests is typically [YYYYMMDD_HHMMSS].
void Account::_displayTimestamp( void )
{
    // Option A: real system time
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

    // Format: [YYYYMMDD_HHMMSS]
    std::cout << "[" << (1900 + ltm->tm_year);
    if ((1 + ltm->tm_mon) < 10) std::cout << "0";
    std::cout << (1 + ltm->tm_mon);
    if (ltm->tm_mday < 10) std::cout << "0";
    std::cout << ltm->tm_mday << "_";
    if (ltm->tm_hour < 10) std::cout << "0";
    std::cout << ltm->tm_hour;
    if (ltm->tm_min < 10) std::cout << "0";
    std::cout << ltm->tm_min;
    if (ltm->tm_sec < 10) std::cout << "0";
    std::cout << ltm->tm_sec << "] ";
    
    // Option B (for debugging): fixed date/time from 42’s examples
    // std::cout << "[19920104_091532] ";
}
