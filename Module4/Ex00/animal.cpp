#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "[ANIMAL] Animal class has been called" << std::endl;
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
