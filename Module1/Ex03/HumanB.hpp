
#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public : 
        HumanB(const std::string name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon& new_weapon);
    private: 
        std::string name;
        Weapon* weapon;

};
