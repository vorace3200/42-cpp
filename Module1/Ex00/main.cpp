#include <iostream>
#include "Zombie.hpp"

int main() {
    Zombie* best_zombie = newZombie("Foo");
    best_zombie->announce();
    randomChump("RandomGuy");
    delete best_zombie;
    return 0;
}