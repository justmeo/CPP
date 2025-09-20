/*
C++98, -Wall -Wextra -Werror, no "using namespace std".
Implement class RPN:

int evaluate(const std::string& expr): parses space-separated tokens.

Use std::stack<int> _st; push single-digit numbers [0..9].

For operator tokens "+ - * /": pop two operands (b,a), compute b op a, push result.

If insufficient operands, invalid token, division by zero, or leftover stack size != 1 at end -> throw std::runtime_error("Error").

Keep interface tiny; implementation in .cpp.
*/

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int evaluate(const std::string& expr);
};

#endif