#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    

    std::cout << std::endl;


    // weapon class testing;
    Weapon* ak_47 = new Weapon;
    ak_47->setType("weapon_assaultrifle");
    std::cout << "Type of the weapon : " << ak_47->getType() << std::endl;

    std::cout << "\n ======================== \n" << std::endl;

    // HumanA class testing
    HumanA* PlayerA = new HumanA(std::string("debug1"), *ak_47);
    PlayerA->attack();


    std::cout << "\n ======================== \n" << std::endl;

    // HumanB class testing
    HumanB*  PlayerB = new HumanB(std::string("debug2"));
    PlayerB->attack();

    Weapon* pistol = new Weapon;
    pistol->setType("weapon_pistol");


    PlayerB->setWeapon(pistol);
    PlayerB->attack();


    std::cout << std::endl;
    delete ak_47;
    delete PlayerA;
    delete PlayerB;
    delete pistol;
    return 0;
}