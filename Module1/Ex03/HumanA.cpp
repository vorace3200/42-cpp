#include "HumanA.hpp"

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {}
HumanA::~HumanA() {}