#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

    public:
        static void convert(std::string literal);
};
