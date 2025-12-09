#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "Prisoner");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try
    {
        rrf = someRandomIntern.makeForm("invalid form", "Nowhere");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
