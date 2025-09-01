#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
int main() {
    FragTrap player1("player1");
    FragTrap player2("player2");

    player2.attack("player1");
    
    player1.takeDamage(30);
    player2.highFivesGuys();
    player1.beRepaired(30);

    return 1;
}