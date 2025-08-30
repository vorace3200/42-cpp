#pragma once
#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();

        void guardGate();
        void attack(const std::string& target);


};
