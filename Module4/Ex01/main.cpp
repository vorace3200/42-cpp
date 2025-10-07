#include <iostream>
#include <string>

#include "animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    std::cout << std::endl;
    std::cout << "======== Array test ========" << std::endl;
    
    Animal* animals[4];
    
    std::cout << "---DOG---" << std::endl;
    for (int idx = 0; idx < 2; idx++)
        animals[idx] = new Dog();
        
    std::cout << "---CAT---" << std::endl;
    for (int idx = 2; idx < 4; idx++)
        animals[idx] = new Cat();

    std::cout << "---DELETE---" << std::endl;
    for (int idx = 0; idx < 4; idx++)
        delete animals[idx];
        
    
    std::cout << std::endl; std::cout << "======== Copy test ========" << std::endl;
    
    Dog HeGotanIdea;
    HeGotanIdea.setIdea(1, "test hello");
    Dog HeStealTheIdea = HeGotanIdea;
    std::cout << "Copy idea : " << HeStealTheIdea.getIdea(1) << std::endl;
    
    return 0;
}