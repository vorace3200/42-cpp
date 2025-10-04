#include "HumanB.hpp"

void HumanB::attack()
{
    if (!this->weapon)
    {
        std::cout << this->name << " doesn't have weapon to attack (unarmed)" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& new_weapon)
{
    this->weapon = &new_weapon;
}

HumanB::HumanB(const std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {};