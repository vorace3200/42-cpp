#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    Zombie* Zombies = new Zombie[n];

    for (int i = 0; i < n; i++)
    {
        Zombies[i].setName(name);
    }
    return Zombies;
}  