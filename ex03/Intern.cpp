#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm* form = nullptr;
    if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else {
        std::cerr << "Error: Form name '" << formName << "' is not recognized." << std::endl;
        return nullptr;
    }
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}
