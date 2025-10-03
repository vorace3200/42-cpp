#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[BRAIN] Hello from the constructor" << std::endl;
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


Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] copy-assign\n";
    if (this != &other) {
        for (size_t i = 0; i < 100; ++i) 
            ideas[i] = other.ideas[i]; // "deep copy" car on vas aller chercher les ideas de celui qu'on prend pour les copiers sur le notre;
    }
    return *this;
}