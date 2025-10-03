#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[DOG] Class has been created with brain" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "[DOG] Class has been destroyed and brain" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->type << " say: Wouuuuuuuf" << std::endl;
}


void Dog::setIdea(int i, const std::string idea)
{
    this->brain->setIdea(i, idea);
}
std::string Dog::getIdea(int i)
{
    return this->brain->getIdea(i);
}