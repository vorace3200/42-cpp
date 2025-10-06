#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[DOG] Class has been created with brain" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "[DOG] Copy constructor called" << std::endl;
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


void Dog::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}
std::string Dog::getIdea(int i)
{
    return this->brain->getIdea(i);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[DOG] Assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}