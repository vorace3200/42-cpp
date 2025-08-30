#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav_Player1("Player1");
    ScavTrap scav_Player2("Player2");
    
    scav_Player1.attack("Player2");
    scav_Player2.takeDamage(20);

    scav_Player2.guardGate();
    return 1;
}