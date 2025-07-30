#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.increment();
        std::cout << bob << std::endl;
        bob.increment(); // throws GradeTooHighException
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 151); // throws GradeTooLowException
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 149);
        std::cout << john << std::endl;
        john.decrement();
        std::cout << john << std::endl;
        john.decrement(); // now grade = 151 throws
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}