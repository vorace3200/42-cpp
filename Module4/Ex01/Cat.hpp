#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        void makeSound() const;
        
    private:
        Brain* brain;
    
};