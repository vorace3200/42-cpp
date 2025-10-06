#include <iostream>
#include <string>

#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    const Animal* other = new Animal();
    const Animal* npc_dog = new Dog();
    const Animal* npc_cat = new Cat();
    const WrongAnimal* wrong_npc_cat = new WrongCat();
    std::cout << "=============== CAT CLASS ===============" << std::endl << std::endl;

    std::cout << "[MAIN] Animal Cat type: " << npc_cat->getType() << std::endl;
    std::cout << "[MAIN] Animal Cat sound: ";  npc_cat->makeSound(); std::cout << std::endl;

    std::cout << "=============== CAT CLASS ===============" << std::endl << std::endl;

    std::cout << "[MAIN] Animal Dog type: " << npc_dog->getType() << std::endl;
    std::cout << "[MAIN] Animal Dog sound: ";  npc_dog->makeSound(); std::cout << std::endl;

    std::cout << "=============== ANIMAL CLASS ===============" << std::endl << std::endl;
    std::cout << "[MAIN] Animal type: " << other->getType() << std::endl;
    std::cout << "[MAIN] Animal sound: "; other->makeSound(); std::cout << std::endl;

    std::cout << "=============== WRONG CAT CLASS ===============" << std::endl << std::endl;
    std::cout << "[MAIN] WRONG Animal Cat type: " << wrong_npc_cat->getType() << std::endl;
    std::cout << "[MAIN] WRONG Animal Cat sound: ";  wrong_npc_cat->makeSound(); std::cout << std::endl;


    delete other;
    delete npc_dog;
    delete npc_cat;
    delete wrong_npc_cat;
    return 0;
}