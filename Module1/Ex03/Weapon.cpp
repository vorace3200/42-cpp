#include "Weapon.hpp"

std::string Weapon::getType() { 
    return this->type;
}

void Weapon::setType(std::string new_type) { 
    this->type = new_type;
    return;
}