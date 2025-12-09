#include "AForm.hpp"
#include "Bureaucrat.hpp"


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form not signed";
}

AForm::AForm(std::string name, int grade_required_sign, int grade_required_execute)
{
    if (grade_required_sign < 1 || grade_required_execute < 1)
        throw AForm::GradeTooHighException();
    else if (grade_required_sign > 150 || grade_required_execute > 150)
        throw AForm::GradeTooLowException();
    this->name = name;
    this->grade_required_sign = grade_required_sign;
    this->grade_required_execute = grade_required_execute;
    this->FormSigned = false;
}

AForm::AForm(AForm& other)
{
    this->name = other.name;
    this->grade_required_sign = other.grade_required_sign;
    this->grade_required_execute = other.grade_required_execute;
    this->FormSigned = other.FormSigned;    
}

AForm& AForm::operator=(AForm& other)
{
    this->name = other.name;
    this->grade_required_sign = other.grade_required_sign;
    this->grade_required_execute = other.grade_required_execute;
    this->FormSigned = other.FormSigned;
    return *this;
}

AForm::~AForm()
{

}

int AForm::get_grade_required_sign() const
{
    return this->grade_required_sign;
}

int AForm::get_grade_required_execute() const
{
    return this->grade_required_execute;
}

bool AForm::is_signed() const
{
    return this->FormSigned;
}

std::string AForm::getName() const
{
    return this->name;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_required_sign)
        throw AForm::GradeTooLowException();
    this->FormSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form " << f.getName() << " is " << (f.is_signed() ? "signed" : "not signed") << " and grade required to sign: " << f.get_grade_required_sign() << " and grade required to execute: " << f.get_grade_required_execute();
    return os;
}
