#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
        // name, signGrade, execGrade are const
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "true" : "false")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade();
    return os;
}