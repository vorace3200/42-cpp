#include "Bureaucrat.hpp"
#include "AForm.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();

    grade--;
    std::cout << "Bureaucrat have a new grade ! : " << grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();

    grade++;
    std::cout << "Bureaucrat have a new grade ! : " << grade << std::endl;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "[DEBUG] Bureaucrat " << name << " created with the grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "[DEBUG] Bureaucrat " << name << " created with the grade: " << grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "[Bureaucrat] Operator called" << std::endl;

    if (this != &other)
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "[Bureaucrat] Copy constructor called" << std::endl;

    name = other.name;
    grade = other.grade;   
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "[DEBUG] Bureaucrat " << name << " destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
