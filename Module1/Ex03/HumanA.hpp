#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string name, Weapon& weapon);
        ~HumanA();
        void attack() const;

    private: 
        Weapon& weapon;
        std::string name;
};
