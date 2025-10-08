#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "[DOG] Class has been created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[DOG] Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[DOG] Class has been destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->type << " say: Wouuuuuuuf" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[DOG] Assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}
