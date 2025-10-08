#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "[CAT] Class has been created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[CAT] Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[CAT] Class has been destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->type << " say: Miaouuuuuuuu" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[CAT] Assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}
