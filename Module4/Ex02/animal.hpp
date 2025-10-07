#pragma once

#include <iostream>
#include <string>

class Animal
{
    
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator=(const Animal& other);
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string type;

};