#include <iostream>
#include <string>

void print_upchar(std::string string)
{
    for (size_t i = 0; i < string.length(); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }
    std::cout << string << std::endl;
}

int main(int a, char **b ) {
    if (a > 1)
    {
        for (int i = 1; i < a; i++)
        {
            print_upchar(b[i]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    

    return 0;
}