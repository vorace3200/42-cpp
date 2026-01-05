#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::cout << "Finding 20." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Finding 42." << std::endl;
        it = easyfind(vec, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    try {
        std::cout << "Finding 300." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 300);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Finding 5." << std::endl;
        it = easyfind(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
