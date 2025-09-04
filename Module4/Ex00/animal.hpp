#pragma once

#include <iostream>
#include <string>

class Animal
{
    
    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound();

        const std::string getType();
    protected:
        std::string type;

};