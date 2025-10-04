#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {

    {
        std::cout << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {
        std::cout << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    
    {
        std::cout << std::endl;
        Weapon ak = Weapon("weapon_assaultriffle");
        HumanB john("John");
        john.attack();
        john.setWeapon(ak);
        john.attack();
    }


    return 0;
}