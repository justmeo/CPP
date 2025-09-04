#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
        // const members left unchanged
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade();
    return os;
}
