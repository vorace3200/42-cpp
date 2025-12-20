#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    try {
        Span hugeSpan(10000);
        std::vector<int> randoms;
        for (int i = 0; i < 10000; i++)
            randoms.push_back(std::rand());
        
        hugeSpan.addNumber(randoms.begin(), randoms.end());
        
        std::cout << "Shortest: " << hugeSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << hugeSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span empty(5);
        empty.addNumber(1);
        empty.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "Expected Exception 1: " << e.what() << std::endl;
    }

    try {
        Span full(2);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "Expected Exception 2: " << e.what() << std::endl;
    }

    return 0;
}
