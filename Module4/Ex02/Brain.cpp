#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[BRAIN] Hello from the constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "[BRAIN] Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "[BRAIN] Goodbye from the destructor" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    if (i < 100) 
        ideas[i] = idea;
}

const std::string Brain::getIdea(int i) const
{
    return this->ideas[i];
}


Brain& Brain::operator=(const Brain& other)
{
    std::cout << "[BRAIN] Assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}