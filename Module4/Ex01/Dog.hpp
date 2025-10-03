#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        void makeSound() const;
        
        std::string getIdea(int i);
        void setIdea(int i, std::string idea);
    private:
        Brain* brain;
    
};