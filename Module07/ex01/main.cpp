#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

void increment(int& num)
{
    num++;
}

void toUpper(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}

int main()
{
    int array[] = {0, 1, 2, 3, 4};
    size_t length = 5;
    iter(array, length, print<int>);
    iter(array, length, increment);
    iter(array, length, print<int>);

    std::string strArray[] = {"hello", "world", "42"};
    length = 3;
    iter(strArray, length, print<std::string>);
    iter(strArray, length, toUpper);
    iter(strArray, length, print<std::string>);

    const int constArray[] = {10, 20, 30};
    length = 3;
    // iter(constArray, length, increment);
    
    iter(constArray, length, print<int>);

    return 0;
}
