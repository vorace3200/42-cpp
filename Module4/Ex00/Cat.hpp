#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        void makeSound() const;
    
};