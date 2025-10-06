#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[ANIMAL] WrongAnimal class has been called" << std::endl;
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
