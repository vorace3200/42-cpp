#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->get_grade_required_execute())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "       _-_" << std::endl;
        outfile << "    /~~   ~~\\" << std::endl;
        outfile << " /~~         ~~\\" << std::endl;
        outfile << "{               }" << std::endl;
        outfile << " \\  _-     -_  /" << std::endl;
        outfile << "   ~  \\\\ //  ~" << std::endl;
        outfile << "_- -   | | _- _" << std::endl;
        outfile << "  _ -  | |   -_" << std::endl;
        outfile << "      // \\\\" << std::endl;
        outfile.close();
    }
}
