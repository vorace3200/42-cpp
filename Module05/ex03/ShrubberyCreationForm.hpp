#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;

    private:
        std::string target;
};
