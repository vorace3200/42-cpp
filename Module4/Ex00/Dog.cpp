#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "[DOG] Class has been created" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[DOG] Class has been destroyed" << std::endl;
}

void Dog::makeSound()
{
    std::cout << this->type << " say: Wouuuuuuuf" << std::endl;
}
