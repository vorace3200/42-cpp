#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <ostream>
class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        
        int getRawBits() const;
        float toFloat() const;
        int toInt() const;
        void setRawBits(int const raw);

    private:
        int value;
        static const int factor = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);