#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "[CAT] Class has been created" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[CAT] Class has been destroyed" << std::endl;
}

void Cat::makeSound()
{
    std::cout << this->type << " say: Miaouuuuuuuu" << std::endl;
}
