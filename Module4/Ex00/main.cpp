#include <iostream>
#include <string>

#include "animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* other = new Animal();
    const Animal* npc_dog = new Dog();
    const Animal* npc_cat = new Cat();

    Animal* other = new Animal;
    std::cout << "=============== CAT CLASS ===============" << std::endl << std::endl;

    std::cout << "[MAIN] Animal Cat type: " << npc_cat->getType() << std::endl;
    std::cout << "[MAIN] Animal Cat sound: ";  npc_cat->makeSound(); std::cout << std::endl;

    std::cout << "=============== CAT CLASS ===============" << std::endl << std::endl;

    std::cout << "[MAIN] Animal Dog type: " << npc_dog.getType() << std::endl;
    std::cout << "[MAIN] Animal Dog sound: ";  npc_dog.makeSound(); std::cout << std::endl;

    std::cout << "=============== ANIMAL CLASS ===============" << std::endl << std::endl;
    std::cout << "[MAIN] Animal type: " << other->getType() << std::endl;
    std::cout << "[MAIN] Animal sound: "; other->makeSound(); std::cout << std::endl;

    return 0;
}