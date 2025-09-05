#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string target;
public:
    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();
    virtual void executeAction() const;
};

#endif
