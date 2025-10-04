#include <iostream>
#include <string>
#include "fixed.hpp"

int main() {
    
    Fixed a;
    a.setRawBits(10);

    Fixed b( a );
    Fixed c;

    c = b;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;


    c.setRawBits(8);
    std::cout << c.getRawBits() << std::endl;

    return 0;
}