#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);
        void makeSound() const;
        
        std::string getIdea(int i);
        void setIdea(int i, std::string idea);
        
    private:
        Brain* brain;
    
};