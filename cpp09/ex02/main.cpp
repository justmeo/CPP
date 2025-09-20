/*
Main must:

If argc < 2: print "Error" to std::cerr and return 1.

Parse args into both a vector and a deque.

Print "Before: " + original numbers once (preserve original order).

Copy original into vec and deq; time sortVector(vec) and sortDeque(deq).

Print "After: " + sorted numbers once (from vec is fine; they should be identical).

Print two timing lines, clearly indicating the container.

Catch exceptions and print "Error" to std::cerr.
*/

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try
    {
        std::vector<unsigned int> vecNumbers;
        std::deque<unsigned int> deqNumbers;
        
        // Parse arguments
        if (!PmergeMe::parseArgs(argc, argv, vecNumbers) ||
            !PmergeMe::parseArgs(argc, argv, deqNumbers))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        
        if (vecNumbers.empty())
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        
        // Print before
        PmergeMe::printSequence("Before:", vecNumbers);
        
        // Create copies for sorting
        std::vector<unsigned int> vecCopy = vecNumbers;
        std::deque<unsigned int> deqCopy = deqNumbers;
        
        // Time vector sorting
        clock_t startVec = clock();
        PmergeMe::sortVector(vecCopy);
        clock_t endVec = clock();
        
        // Time deque sorting
        clock_t startDeq = clock();
        PmergeMe::sortDeque(deqCopy);
        clock_t endDeq = clock();
        
        // Print after
        PmergeMe::printSequence("After:", vecCopy);
        
        // Print timing information
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << vecNumbers.size() 
                  << " elements with std::vector : " 
                  << PmergeMe::elapsedMicros(startVec, endVec) << " us" << std::endl;
        std::cout << "Time to process a range of " << deqNumbers.size() 
                  << " elements with std::deque : " 
                  << PmergeMe::elapsedMicros(startDeq, endDeq) << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}