#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}

static AForm* makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(std::string target) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }
    
    std::cout << "Intern can't create " << name << " because it doesn't exist" << std::endl;
    throw Intern::FormNotFoundException();
}
