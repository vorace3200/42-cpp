#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[CAT] Class has been created with brain" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "[CAT] Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[CAT] Class has been destroyed and brain" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->type << " say: Miaouuuuuuuu" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i)
{
    return this->brain->getIdea(i);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[CAT] Assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}
