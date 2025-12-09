#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->get_grade_required_execute())
        throw AForm::GradeTooLowException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
