/*
Goal: small main that:

checks argc == 2; else prints "Error: could not open file." and returns 1.

constructs BitcoinExchange, loads "data.csv" from current dir, then calls evaluateFile(argv[1]).

catches std::exception and prints an error if thrown.
*/

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try
    {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.evaluateFile(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}