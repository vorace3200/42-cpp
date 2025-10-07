#pragma once

#include <iostream>
#include <string>

class Animal
{
    
    public:
        Animal();
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const;

         std::string getType() const;
    protected:
        std::string type;

};