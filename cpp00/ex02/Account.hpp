#pragma once
#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#include <iostream>

class Account {

public:

    // Constructors & destructor
    Account( int initial_deposit );
    ~Account( void );

    // Accessors
    static int  getNbAccounts( void );
    static int  getTotalAmount( void );
    static int  getNbDeposits( void );
    static int  getNbWithdrawals( void );

    static void displayAccountsInfos( void );

    void        makeDeposit( int deposit );
    bool        makeWithdrawal( int withdrawal );
    int         checkAmount( void ) const;
    void        displayStatus( void ) const;

private:

    static int  _nbAccounts;
    static int  _totalAmount;
    static int  _totalNbDeposits;
    static int  _totalNbWithdrawals;

    static void _displayTimestamp( void );

    int         _accountIndex;
    int         _amount;
    int         _nbDeposits;
    int         _nbWithdrawals;

    Account( void ); // Default constructor is private/forbidden (not used)

};

#endif
