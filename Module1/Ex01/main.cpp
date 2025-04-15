#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;

    while (1)
    {
        std::string choice;
        std::cout << "Enter your choice in the menu:" << std::endl;

        std::cin >> choice;

        if (choice == "ADD")
        {

            Contact contact;
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string phone_number;
            std::string darkest_secret;

            std::cout << "Enter the first name of the contact: " << std::endl;
            std::cin >> first_name;
            std::cout << "Enter the last name of the contact: " << std::endl;
            std::cin >> last_name;
            std::cout << "Enter the nickname of the contact: " << std::endl;
            std::cin >> nickname;
            std::cout << "Enter the phone number of the contact: " << std::endl; 
            std::cin >> phone_number;
            std::cout << "Enter the darkest secret of the contact: " << std::endl;
            std::cin >> darkest_secret;

            contact.set_informations(first_name, last_name, nickname, phone_number, darkest_secret);
            phonebook.add_contact(contact);
            std::cout << "Contact added successfully" << std::endl;

        }
        else if (choice == "SEARCH")
        {
            phonebook.search_contact();
        }
        else if (choice == "DEBUG")
        {
            for (int i = 0; i < 8; i++)
            {
                Contact contact;
                contact.set_informations("John", "Doe", "John Doe", "1234567890", "This is a secret");
                phonebook.add_contact(contact);
            }
            std::cout << "8 contacts added successfully" << std::endl;
        }
        else if (choice == "HELP")
        {
            std::cout << "[ADD] This command add a new contact in the phonebook." << std::endl;
            std::cout << "[SEARCH] Show a list of your current contacts and you can search information. " << std::endl;
            std::cout << "[EXIT] exit?" << std::endl;
        }
        else if (choice == "EXIT")
        {
            std::cout << "Exiting..." << std::endl;
            return (0);
        }
        else
        {
            std::cout << "[ERROR] Command not found please type 'HELP'" << std::endl;
        }
    }
  

}