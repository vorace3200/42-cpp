#include "Bureaucrat.hpp"

int main() {
    std::cout << "[DEBUG] Hello" << std::endl;

    Bureaucrat John("John", 1);
    Bureaucrat Jane("Jane", 150);

    try
    {
        John.decrementGrade();
        John.decrementGrade();
        Jane.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << John << std::endl;
    std::cout << Jane << std::endl;


    std::cout << "[DEBUG] Program finshed." << std::endl;

	return 0;
}