#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[CAT] Class has been created with brain" << std::endl;
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
