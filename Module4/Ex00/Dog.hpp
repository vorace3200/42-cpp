#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        void makeSound();
    
};