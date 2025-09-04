#include "Zombie.hpp"

Zombie::Zombie() : name("")
{

}

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed." << std::endl;
}

Zombie::Zombie(const std::string& name) : name(name)
{

}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::string zombie_name = this->name;
    std::cout << zombie_name << ":" << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}