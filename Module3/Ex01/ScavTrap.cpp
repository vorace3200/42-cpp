#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hit = 100;
    energy = 50;
    damage = 20;
    std::cout << "ScavTrap constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor has been called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap : " << name << " his now in guard gate state." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit <= 0 || energy <= 0) {
        std::cout << name << " can't attack (no HP or Energy)." << std::endl;
        return;
    }
    --energy;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;

}