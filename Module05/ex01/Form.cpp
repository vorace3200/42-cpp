#include "Form.hpp"
#include "Bureaucrat.hpp" // Required for check


const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

Form::Form()
{
    this->name = "Default Form";
    this->grade_required_sign = 150;
    this->grade_required_execute = 150;
    this->FormSigned = false;
}

Form::Form(std::string name, int grade_required_sign, int grade_required_execute)
{
    if (grade_required_sign < 1 || grade_required_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_required_sign > 150 || grade_required_execute > 150)
        throw Form::GradeTooLowException();
    this->name = name;
    this->grade_required_sign = grade_required_sign;
    this->grade_required_execute = grade_required_execute;
    this->FormSigned = false;
}

Form::Form(const Form& other)
{
    this->name = other.name;
    this->grade_required_sign = other.grade_required_sign;
    this->grade_required_execute = other.grade_required_execute;
    this->FormSigned = other.FormSigned;    
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->grade_required_sign = other.grade_required_sign;
        this->grade_required_execute = other.grade_required_execute;
        this->FormSigned = other.FormSigned;
    }
    return *this;
}

Form::~Form()
{

}

int Form::get_grade_required_sign() const
{
    return this->grade_required_sign;
}

int Form::get_grade_required_execute() const
{
    return this->grade_required_execute;
}

bool Form::is_signed() const
{
    return this->FormSigned;
}

std::string Form::getName() const
{
    return this->name;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_required_sign)
        throw Form::GradeTooLowException();
    this->FormSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName() << " is " << (f.is_signed() ? "signed" : "not signed") << " and grade required to sign: " << f.get_grade_required_sign() << " and grade required to execute: " << f.get_grade_required_execute();
    return os;
}