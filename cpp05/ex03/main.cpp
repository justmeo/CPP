#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Ford");

    // Signing attempts
    intern.signForm(shrub);
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << std::endl;

    // Execution attempts
    intern.executeForm(shrub);
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    return 0;
}