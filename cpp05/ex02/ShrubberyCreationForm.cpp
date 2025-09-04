#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs((target + "_shrubbery").c_str());
    ofs << "   _\\/_" << std::endl
        << "    /\\" << std::endl
        << "    /\\" << std::endl
        << "   /  \\" << std::endl;
    ofs.close();
}
