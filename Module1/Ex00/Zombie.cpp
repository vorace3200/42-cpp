#include "Zombie.hpp"


void Zombie::setName(std::string name)
{
    this->name = name;
}
Zombie* Zombie::NewZombie(std::string name)
{
    Zombie* zombie = new Zombie();
    zombie->name = name;
    return zombie;
}

void Zombie::announce()
{
    std::string zombie_name = this->name;
    std::cout << zombie_name << ":" << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}