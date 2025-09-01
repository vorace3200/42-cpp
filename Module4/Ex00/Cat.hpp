#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        void makeSound();
    
};