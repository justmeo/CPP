#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form) {
        delete form;
    }

    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form) {
        delete form;
    }

    return 0;
}
