#pragma once
#include <iostream>
#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
    public:
        Form(std::string name, int grade_required_sign, int grade_required_execute);
        Form(Form& other);
        Form& operator=(Form& other);
        ~Form();

        std::string getName() const;
        int get_grade_required_sign() const;
        int get_grade_required_execute() const;
        bool is_signed() const;

        void beSigned(const Bureaucrat& bureaucrat);

        

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        

    private:
        std::string name;
        int grade_required_sign;
        int grade_required_execute;
        bool FormSigned;

};

std::ostream& operator<<(std::ostream& os, const Form& b);