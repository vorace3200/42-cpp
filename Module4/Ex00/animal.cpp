#include "animal.hpp"

Animal::Animal()
{
    std::cout << "[ANIMAL] Animal class has been called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "[ANIMAL] Animal destructor has been called" << std::endl;
}

const std::string Animal::getType()
{
    return this->type;
}

void Animal::makeSound()
{
    std::cout << this->type << " say: grrr" << std::endl;
}
