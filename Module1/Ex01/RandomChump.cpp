#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie;
    Zombie* ptr = zombie.NewZombie(name);
    ptr->announce();
    delete ptr;
}
