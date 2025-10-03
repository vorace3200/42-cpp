#include <iostream>
#include "Zombie.hpp"

int main() {
    Zombie* Zombies = zombieHorde(10, "ZombieGang");

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Announcing Zombie ID: #" << i << std::endl;
        Zombies[i].announce();
    }
    delete[] Zombies;
    return 0;
}