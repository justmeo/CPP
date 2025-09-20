/*
You are generating C++98 code for 42's C++ Module 09 ex00 (program name: btc).
Rules:

No "using namespace std;".

Must compile with -Wall -Wextra -Werror -std=c++98.

Use std::map<string,double> to store date->price from data.csv.

Provide a class BitcoinExchange with:

loadDatabase(const std::string& csvPath): parses "date,price" into map, validates date format "YYYY-MM-DD".

evaluateFile(const std::string& inputPath): reads lines "YYYY-MM-DD | value", validates, finds price for date or closest lower date via map.lower_bound and decrement when not exact, then prints "date => value = value*price".

clear, getters for testing if needed.

Robust error handling:

If cannot open files: "Error: could not open file."

If bad input format: "Error: bad input => <line>".

If negative value: "Error: not a positive number."

If value > 1000: "Error: too large a number."

Date validation: basic checks (length 10, digits and hyphens positions, 1..12 month, 1..31 day), no <algorithm>.

No dynamic allocations unless necessary. No headers-only implementations (put impl in .cpp).
*/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr) const;
    double parseValue(const std::string& valueStr) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& csvPath);
    void evaluateFile(const std::string& inputPath);
    void clear();
};

#endif