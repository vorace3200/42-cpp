#include <iostream>
#include <string>
#include "fixed.hpp"

int main() {
    
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    Fixed c(10);
    std::cout << c << std::endl;
    std::cout << c*10 << std::endl;
    std::cout << c/10 << std::endl;

    return 0;
}