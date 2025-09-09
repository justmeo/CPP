#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

// You must write your own tests. Here's a minimal harness:
// NOTE: All outputs should end with a newline per general rules.

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 3);

    try {
        // Test found case
        std::vector<int>::iterator it = easyfind(v, 9);
        std::cout << "Found: " << *it << std::endl;
        
        // Test with different container
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::list<int>::iterator lit = easyfind(lst, 2);
        std::cout << "Found in list: " << *lit << std::endl;
        
        // Test const version
        const std::vector<int> cv = v;
        std::vector<int>::const_iterator cit = easyfind(cv, 6);
        std::cout << "Found (const): " << *cit << std::endl;
        
        // Test not found case - should throw
        easyfind(v, 100);
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}