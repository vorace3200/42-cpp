#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
    
    public:
        WrongAnimal();
        ~WrongAnimal();
        void makeSound() const;

        std::string getType() const;
    protected:
        std::string type;

};