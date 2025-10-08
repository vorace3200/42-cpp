#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[ANIMAL] WrongAnimal class has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type = other.type;
    std::cout << "[ANIMAL] WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[ANIMAL] WrongAnimal destructor has been called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->type << " say: grrr" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "[ANIMAL] WrongAnimal assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}
