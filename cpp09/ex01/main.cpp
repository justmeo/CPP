/*
If argc != 2: print "Error" to std::cerr and return 1.
Else construct RPN and call evaluate(argv[1]); print result to std::cout << result << "\n".
Catch exceptions and print "Error" to std::cerr.
*/

#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try
    {
        RPN rpn;
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}