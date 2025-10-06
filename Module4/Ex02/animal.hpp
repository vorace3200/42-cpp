#pragma once

#include <iostream>
#include <string>

class Animal
{
    
    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const = 0;

         std::string getType() const;
    protected:
        std::string type;

};