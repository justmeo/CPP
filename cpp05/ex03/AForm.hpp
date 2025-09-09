#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too low"; }
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw() { return "Form not signed"; }
    };

    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;
    virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif
