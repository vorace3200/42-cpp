#include "Weapon.hpp"

Weapon::~Weapon() {};

const std::string Weapon::getType() const { 
    return this->type;
}

void Weapon::setType(const std::string new_type) { 
    this->type = new_type;
}

Weapon::Weapon(const std::string type) : type(type) {}