/*
Implement:

parseArgs: for each argv[i], ensure only digits, no sign, value fits unsigned and > 0. (Optionally track duplicates in a set-like check; either reject or accept—subject leaves it to you.)

For vector version:

Make vector of pairs< unsigned, unsigned > where pair.first = big, pair.second = small.

Sort pairs by 'first' using your own insertion or merge (no <algorithm>).

Build main chain from all 'first's.

Determine Jacobsthal insertion order for indices of 'second's; insert each 'second' via binaryInsertVector into main chain.

If odd straggler existed, insert it at the end with binary search insert.

Mirror the same logic for deque version.

printSequence("Before:", seq) and printSequence("After:", seq) as required.

Time the vector pipeline and the deque pipeline separately; print:
"Time to process a range of <N> elements with std::vector : X.XXXXX us"
"Time to process a range of <N> elements with std::deque : X.XXXXX us"
(Format close to subject; microsecond-level precision.)
*/

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{ 
    (void)other; 
    return *this; 
}

bool PmergeMe::parseArgs(int argc, char** argv, std::vector<unsigned int>& out)
{
    out.clear();
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            return false;
        
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (arg[j] < '0' || arg[j] > '9')
                return false;
        }
        
        std::stringstream ss(arg);
        unsigned long val;
        ss >> val;
        
        if (val == 0 || val > 4294967295UL)
            return false;
        
        out.push_back(static_cast<unsigned int>(val));
    }
    return true;
}

bool PmergeMe::parseArgs(int argc, char** argv, std::deque<unsigned int>& out)
{
    out.clear();
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            return false;
        
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (arg[j] < '0' || arg[j] > '9')
                return false;
        }
        
        std::stringstream ss(arg);
        unsigned long val;
        ss >> val;
        
        if (val == 0 || val > 4294967295UL)
            return false;
        
        out.push_back(static_cast<unsigned int>(val));
    }
    return true;
}

void PmergeMe::printSequence(const char* label, const std::vector<unsigned int>& v)
{
    std::cout << label;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

void PmergeMe::printSequence(const char* label, const std::deque<unsigned int>& d)
{
    std::cout << label;
    for (size_t i = 0; i < d.size(); i++)
    {
        std::cout << " " << d[i];
    }
    std::cout << std::endl;
}

double PmergeMe::elapsedMicros(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    if (n == 0)
        return jacobsthal;
    
    // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43, 85, ...
    std::vector<size_t> jac;
    jac.push_back(1);
    if (n > 1)
        jac.push_back(1);
    
    while (jac.back() < n)
    {
        size_t next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        jac.push_back(next);
    }
    
    // Build insertion order
    jacobsthal.push_back(0); // First element (index 0)
    
    for (size_t i = 2; i < jac.size() && jac[i] <= n; i++)
    {
        size_t start = jac[i] - 1;
        size_t end = (i > 2) ? jac[i - 1] : 1;
        
        for (size_t j = start; j >= end && j < n; j--)
        {
            jacobsthal.push_back(j);
        }
        if (end == 0)
            break;
    }
    
    // Add remaining indices
    for (size_t i = 0; i < n; i++)
    {
        bool found = false;
        for (size_t j = 0; j < jacobsthal.size(); j++)
        {
            if (jacobsthal[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            jacobsthal.push_back(i);
    }
    
    return jacobsthal;
}

void PmergeMe::binaryInsertVector(std::vector<unsigned int>& vec, unsigned int value, size_t end)
{
    if (end == 0)
    {
        vec.insert(vec.begin(), value);
        return;
    }
    
    size_t left = 0;
    size_t right = end;
    
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    vec.insert(vec.begin() + left, value);
}

void PmergeMe::insertionSortVector(std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<unsigned int, unsigned int> key = pairs[i];
        size_t j = i;
        
        while (j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sortVector(std::vector<unsigned int>& v)
{
    if (v.size() <= 1)
        return;
    
    // Step 1: Create pairs
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    unsigned int straggler = 0;
    bool hasStraggler = false;
    
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i] > v[i + 1])
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
        else
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
    
    if (v.size() % 2 == 1)
    {
        straggler = v[v.size() - 1];
        hasStraggler = true;
    }
    
    // Step 2: Sort pairs by their larger element
    insertionSortVector(pairs);
    
    // Step 3: Build main chain from larger elements
    std::vector<unsigned int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }
    
    // Step 4: Insert smaller elements using Jacobsthal order
    if (!pairs.empty())
    {
        // Insert first small element at the beginning
        mainChain.insert(mainChain.begin(), pairs[0].second);
        
        // Generate Jacobsthal sequence for remaining elements
        std::vector<size_t> jacobsthalOrder = generateJacobsthalSequence(pairs.size() - 1);
        
        for (size_t i = 0; i < jacobsthalOrder.size() && jacobsthalOrder[i] + 1 < pairs.size(); i++)
        {
            size_t idx = jacobsthalOrder[i] + 1;
            unsigned int toInsert = pairs[idx].second;
            
            // Find position where pairs[idx].first is in mainChain
            size_t upperBound = 0;
            for (size_t j = 0; j < mainChain.size(); j++)
            {
                if (mainChain[j] == pairs[idx].first)
                {
                    upperBound = j;
                    break;
                }
            }
            
            binaryInsertVector(mainChain, toInsert, upperBound);
        }
    }
    
    // Step 5: Insert straggler if exists
    if (hasStraggler)
    {
        binaryInsertVector(mainChain, straggler, mainChain.size());
    }
    
    v = mainChain;
}

void PmergeMe::binaryInsertDeque(std::deque<unsigned int>& deq, unsigned int value, size_t end)
{
    if (end == 0)
    {
        deq.insert(deq.begin(), value);
        return;
    }
    
    size_t left = 0;
    size_t right = end;
    
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (deq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    deq.insert(deq.begin() + left, value);
}

void PmergeMe::insertionSortDeque(std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<unsigned int, unsigned int> key = pairs[i];
        size_t j = i;
        
        while (j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sortDeque(std::deque<unsigned int>& d)
{
    if (d.size() <= 1)
        return;
    
    // Step 1: Create pairs
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    unsigned int straggler = 0;
    bool hasStraggler = false;
    
    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] > d[i + 1])
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
        else
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
    }
    
    if (d.size() % 2 == 1)
    {
        straggler = d[d.size() - 1];
        hasStraggler = true;
    }
    
    // Step 2: Sort pairs by their larger element
    insertionSortDeque(pairs);
    
    // Step 3: Build main chain from larger elements
    std::deque<unsigned int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }
    
    // Step 4: Insert smaller elements using Jacobsthal order
    if (!pairs.empty())
    {
        // Insert first small element at the beginning
        mainChain.insert(mainChain.begin(), pairs[0].second);
        
        // Generate Jacobsthal sequence for remaining elements
        std::vector<size_t> jacobsthalOrder = generateJacobsthalSequence(pairs.size() - 1);
        
        for (size_t i = 0; i < jacobsthalOrder.size() && jacobsthalOrder[i] + 1 < pairs.size(); i++)
        {
            size_t idx = jacobsthalOrder[i] + 1;
            unsigned int toInsert = pairs[idx].second;
            
            // Find position where pairs[idx].first is in mainChain
            size_t upperBound = 0;
            for (size_t j = 0; j < mainChain.size(); j++)
            {
                if (mainChain[j] == pairs[idx].first)
                {
                    upperBound = j;
                    break;
                }
            }
            
            binaryInsertDeque(mainChain, toInsert, upperBound);
        }
    }
    
    // Step 5: Insert straggler if exists
    if (hasStraggler)
    {
        binaryInsertDeque(mainChain, straggler, mainChain.size());
    }
    
    d = mainChain;
}