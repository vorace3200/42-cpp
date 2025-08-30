#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main() {
    ClapTrap player1("John");
    ClapTrap player2("Arthur");

    player2.takeDamage(3);
    player1.beRepaired(2);
    player1.attack("Arthur");
}