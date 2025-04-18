#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie();
    return zombie->NewZombie(name);
}
