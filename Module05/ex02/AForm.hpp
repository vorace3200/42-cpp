#pragma once
#include <iostream>
#include <string>
#include <ostream>

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string name, int grade_required_sign, int grade_required_execute);
        AForm(AForm& other);
        AForm& operator=(AForm& other);
        virtual ~AForm();

        std::string getName() const;
        int get_grade_required_sign() const;
        int get_grade_required_execute() const;
        bool is_signed() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        
        class NotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& b);
