#pragma once
#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& name);
        ~FragTrap();

        void highFivesGuys(void);

};
