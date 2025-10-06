#include <iostream>
#include <string>

#include "animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
 
    
    std::cout << std::endl;
    std::cout << "==== Array test ====" << std::endl;
    
    Animal* animals[4];
    
    for (int idx = 0; idx < 2; idx++)
        animals[idx] = new Dog();
    for (int idx = 2; idx < 4; idx++)
        animals[idx] = new Cat();
        
    for (int idx = 0; idx < 4; idx++)
        delete animals[idx];
        
    std::cout << std::endl;
    std::cout << "==== Deep copy test ====" << std::endl;
    
    Dog basic;
    Dog tmp = basic;
    
    return 0;
}