#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "[ANIMAL] Animal class has been called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "[ANIMAL] Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "[ANIMAL] Animal destructor has been called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << this->type << " say: grrr" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[ANIMAL] Animal operator alled" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}