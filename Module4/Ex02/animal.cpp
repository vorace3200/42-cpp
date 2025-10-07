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

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[ANIMAL] Animal operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}
