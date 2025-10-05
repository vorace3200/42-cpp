#pragma once

#include <iostream>
#include <string>
class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        
        int getRawBits() const;
        void setRawBits(int const raw);

    private:
        int value;
        static const int factor = 8;

};