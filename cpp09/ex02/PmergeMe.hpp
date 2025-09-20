/*
C++98, -Wall -Wextra -Werror, no "using namespace std".
Implement class PmergeMe with:

static bool parseArgs(int argc, char** argv, std::vector<unsigned int>& out);

static bool parseArgs(int argc, char** argv, std::deque<unsigned int>& out);

static void sortVector(std::vector<unsigned int>& v); // Ford-Johnson: pair, sort-by-big, main chain + Jacobsthal insertion

static void sortDeque(std::deque<unsigned int>& d); // same algorithm, implemented separately

static void printSequence(const char* label, <container>& c);

static unsigned long elapsedMicros(clock_t start, clock_t end); // use clock() timing
No std::algorithm usage; write simple helpers: binaryInsertVector, binaryInsertDeque, makePairs, jacobsthalOrder.
Robust error signaling by throwing std::runtime_error on bad inputs (non-positive, non-numeric).
*/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
    // Vector helpers
    static void binaryInsertVector(std::vector<unsigned int>& vec, unsigned int value, size_t end);
    static void insertionSortVector(std::vector<std::pair<unsigned int, unsigned int> >& pairs);
    
    // Deque helpers
    static void binaryInsertDeque(std::deque<unsigned int>& deq, unsigned int value, size_t end);
    static void insertionSortDeque(std::deque<std::pair<unsigned int, unsigned int> >& pairs);
    
    // Common helpers
    static std::vector<size_t> generateJacobsthalSequence(size_t n);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    static bool parseArgs(int argc, char** argv, std::vector<unsigned int>& out);
    static bool parseArgs(int argc, char** argv, std::deque<unsigned int>& out);
    
    static void sortVector(std::vector<unsigned int>& v);
    static void sortDeque(std::deque<unsigned int>& d);
    
    static void printSequence(const char* label, const std::vector<unsigned int>& v);
    static void printSequence(const char* label, const std::deque<unsigned int>& d);
    
    static double elapsedMicros(clock_t start, clock_t end);
};

#endif