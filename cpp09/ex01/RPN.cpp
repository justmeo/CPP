/*
Implement RPN::evaluate:

Tokenize by spaces only (no decimals; only single-digit ints).

Use long for intermediate safety then cast to int.

Print nothing here; just return the result or throw on error.
*/

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.length() != 1)
        return false;
    return (token[0] >= '0' && token[0] <= '9');
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string& expr)
{
    // Clear stack for fresh evaluation
    while (!_stack.empty())
        _stack.pop();
    
    std::istringstream iss(expr);
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
        {
            int num = token[0] - '0';
            _stack.push(num);
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    
    return _stack.top();
}