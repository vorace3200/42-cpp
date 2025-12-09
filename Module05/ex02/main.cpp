#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    

    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat rob("Rob", 45);
        RobotomyRequestForm robot("target");
        rob.signForm(robot);
        rob.executeForm(robot);
        rob.executeForm(robot);
        rob.executeForm(robot);
        rob.executeForm(robot);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Crime");
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat fail("Fail", 5);
        PresidentialPardonForm pardon("Crime");
        fail.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat weak("Weak", 150);
        ShrubberyCreationForm shrub("garden");
      
        weak.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
