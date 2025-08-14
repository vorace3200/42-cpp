
#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public : 
         HumanB(std::string name) : name(name), weapon(nullptr) {}
        void attack();
        void setWeapon(Weapon* new_weapon);
    private: 
        std::string name;
        Weapon* weapon;

};
