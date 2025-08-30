#pragma once

#include <iostream>
#include <string>
class ClapTrap
{
    public:
        ClapTrap(const std::string& name);

        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string name;
        int hit;
        int energy;
        int damage;
};
