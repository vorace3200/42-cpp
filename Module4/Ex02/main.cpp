#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    //const Animal* notworking = new Animal();
    
    Dog HeGotanIdea;
    HeGotanIdea.setIdea(1, "test hello");
    Dog HeStealTheIdea = HeGotanIdea;
    std::cout << "Copy idea : " << HeStealTheIdea.getIdea(1) << std::endl;
    
    return 0;
}