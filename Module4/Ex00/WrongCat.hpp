#pragma once

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        void makeSound() const;
    
};