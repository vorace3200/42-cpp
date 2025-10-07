#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& other);
        void makeSound() const;
        
        std::string getIdea(int i);
        void setIdea(int i, std::string idea);
    private:
        Brain* brain;
    
};