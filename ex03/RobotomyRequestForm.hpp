#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    const std::string target;
public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();
    virtual void executeAction() const;
};

#endif
