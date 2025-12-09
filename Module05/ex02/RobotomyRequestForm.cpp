#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->get_grade_required_execute())
        throw AForm::GradeTooLowException();

    if (std::rand() % 2 == 0)
        std::cout << this->target << " he's robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
