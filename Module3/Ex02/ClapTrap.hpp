#pragma once

#include <iostream>
#include <string>
class ClapTrap
{
    protected:
        std::string name;
        int hit;
        int energy;
        int damage;

    public:
        ClapTrap(const std::string& name);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};
