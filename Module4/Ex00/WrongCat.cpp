#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Cat";
    std::cout << "[WRONGCAT] Class has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WRONGCAT] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WRONGCAT] Class has been destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " say: Miaouuuuuuuu" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "[WRONGCAT] Assignment operator called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}
