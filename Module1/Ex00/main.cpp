#include <iostream>
#include "Zombie.hpp"

int main() {
    Zombie* new_zombie = newZombie("Oui");
    new_zombie->announce();
    new_zombie->setName("Non");
    new_zombie->announce();
    delete new_zombie;

    randomChump("ouais");
    return 0;
}