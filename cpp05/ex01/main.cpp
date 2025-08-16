#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    Bureaucrat john("John", 50);
    Form contract("Contract", 45, 30);

    std::cout << john << std::endl;
    std::cout << contract << std::endl;

    // Attempt to sign (should fail)
    john.signForm(contract);
    std::cout << contract << std::endl;

    // Promote John then sign
    john.increment(); // grade 49
    john.increment(); // grade 48
    john.increment(); // 47
    john.increment(); // 46
    john.increment(); // 45
    std::cout << john << std::endl;
    john.signForm(contract); // now can sign
    std::cout << contract << std::endl;

    return 0;
}