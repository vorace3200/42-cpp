#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Cat";
    std::cout << "[WRONGCAT] Class has been created" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WRONGCAT] Class has been destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " say: Miaouuuuuuuu" << std::endl;
}
