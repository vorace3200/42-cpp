#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main(int, char**)
{
    std::srand(time(NULL));
    int max_value = 750;
    Array<int> numbers(max_value);
    int* mirror = new int[max_value];
    std::cout << "getSize of numbers : " << numbers.size() << std::endl;

    for (int i = 0; i < max_value; i++)
    {
        int random_value = std::rand();
        numbers[i] = random_value;
        mirror[i] = random_value;
    }

    for (int i = 0; i < max_value; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "They don't have the same value." << std::endl;
            return 1;
        }
    }
    std::cout << "Set working good (mirror == numbers)" << std::endl;
    try
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        if (tmp.size() > 0)
            tmp[0] = -1;
        if (numbers[0] == -1)
        {
             std::cerr << "There is a problem with the deep copy." << std::endl;
             return 1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Copy constructor working good (tmp[0] != numbers[0])" << std::endl;


    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Expected exception: " << e.what() << '\n';
    }

    try
    {
        numbers[max_value] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Expected exception: " << e.what() << '\n';
    }
    
    std::cout << "end of the program :)" << std::endl;

    delete [] mirror;
    return 0;
}
