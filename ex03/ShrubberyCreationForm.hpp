#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string target;
public:
    ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm();
    virtual void executeAction() const;
};

#endif