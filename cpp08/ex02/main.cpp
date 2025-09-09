#include <iostream>
#include <list>
#include "MutantStack.hpp"

// Subject example:
/*
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
*/

int main() {
    // 1) Reproduce the subject example above.
    std::cout << "=== MutantStack Test ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // 2) Replace MutantStack with std::list<int> and its push_back/pop_back to confirm same output.
    std::cout << "\n=== std::list Test (should match above output) ===" << std::endl;
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // Additional tests
    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // Test const iterators
    const MutantStack<int> const_mstack = mstack;
    std::cout << "Const iteration: ";
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    // Test reverse iterators
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}