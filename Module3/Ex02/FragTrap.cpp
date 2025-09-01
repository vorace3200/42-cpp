#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hit = 100;
    energy = 100;
    damage = 30;
    std::cout << "FragTrap constructor has been called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FragTrap] " << this->name << " wants a high five!" << std::endl;
}