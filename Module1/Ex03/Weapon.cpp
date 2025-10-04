#include "Weapon.hpp"

Weapon::~Weapon() {};

std::string Weapon::getType() const { 
    return this->type;
}

void Weapon::setType(std::string new_type) { 
    this->type = new_type;
}

Weapon::Weapon(const std::string type) : type(type) {}