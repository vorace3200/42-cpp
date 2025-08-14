

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {};
        void attack();

    private: 
        Weapon& weapon;
        std::string name;
};
