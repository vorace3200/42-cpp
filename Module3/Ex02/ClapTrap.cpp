#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hit(10), energy(10), damage(0)
{
    std::cout << "ClapTrap constructor has been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit <= 0 || energy <= 0) {
        std::cout << name << " can't attack (no HP or Energy)." << std::endl;
        return;
    }
    --energy;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit <= 0)
    {
        std::cout << this->name << " his already dead." << std::endl;
        return;
    }
    this->hit -= amount;
    if (this->hit < 0)
        this->hit = 0;
    std::cout << name << " takes " << amount << " damage, now has " << hit << " HP." << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit <= 0 || energy <= 0) {
        std::cout << name << " can't repair (no HP or Energy)." << std::endl;
        return;
    }
    --energy;
    hit += static_cast<int>(amount);
    std::cout << name << " repairs " << amount << " HP, now has " << hit << " HP." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor has been called" << std::endl;
}