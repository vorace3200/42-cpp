#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "[DEBUG] Hello" << std::endl;

    Bureaucrat John("John", 1);
    Bureaucrat Jane("Jane", 150);

    try
    {
        Form formA("A", 1, 1);
        std::cout << formA << std::endl;

        Form formB("B", 150, 150);
        std::cout << formB << std::endl;

        John.signForm(formA);
        John.signForm(formB);

        Jane.signForm(formA);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught during Form creation: " << e.what() << std::endl;
    }

    try
    {
        John.decrementGrade();
        // John.decrementGrade();
        // Jane.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught during Bureaucrat modification: " << e.what() << std::endl;
    }

    std::cout << John << std::endl;
    std::cout << Jane << std::endl;


    std::cout << "[DEBUG] Program finshed." << std::endl;

	return 0;
}