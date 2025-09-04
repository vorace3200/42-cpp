#include "PhoneBook.hpp"
#include <iomanip>

void Contact::set_informations(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

std::string Contact::get_informations(int choice)
{
    switch (choice)
    {
        case 0:
            return (this->first_name);
        case 1:
            return (this->last_name );
        case 2:
            return (this->nickname);
        case 3:
            return (this->phone_number);
        case 4:
            return (this->darkest_secret);
        default:
            return ("{NULL}");
    }
}

std::string formatString(std::string str)
{
    std::string result;
    if (str.length() > 10)
        result = str.substr(0, 9) + ".";
    else
        result = str;
    return result;
}

void PhoneBook::search_contact()
{
    std::cout << "|----------|----------|----------|----------|" << std::endl;
   for (int i = 0; i < 8; i++)
   {    
        if (this->contacts[i].get_informations(0) != "{NULL}")
        {
            std::cout << "|" << std::left << std::setw(10) << i;
            
            std::string string = formatString(this->contacts[i].get_informations(0));
            std::cout << "|";
            std::cout << std::left << std::setw(10) << string;
            
            string = formatString(this->contacts[i].get_informations(1));
            std::cout << "|";
            std::cout << std::left << std::setw(10) << string;
            
            string = formatString(this->contacts[i].get_informations(2));
            std::cout << "|";
            std::cout << std::left << std::setw(10) << string;
            std::cout << "|"  << std::endl;
        }
   }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    
    int search_index;
    std::cout << "Enter index of contact to display details: ";
    std::cin >> search_index;
    
    if ((search_index >= 0 && search_index < 8) && !this->contacts[search_index].get_informations(0).empty() )
    {
        std::cout << "First Name: " << this->contacts[search_index].get_informations(0) << std::endl;
        std::cout << "Last Name: " << this->contacts[search_index].get_informations(1) << std::endl;
        std::cout << "Nickname: " << this->contacts[search_index].get_informations(2) << std::endl;
        std::cout << "Phone Number: " << this->contacts[search_index].get_informations(3) << std::endl;
        std::cout << "Darkest Secret: " << this->contacts[search_index].get_informations(4) << std::endl;
    }
    else
    {
        std::cout << "Invalid index or contact not found." << std::endl;
    }
}

void PhoneBook::add_contact(Contact contact)
{
    if (this->index >= 8)
        this->index = 0;
        
    contacts[index] = contact;
    index++;
}

PhoneBook::PhoneBook()
{
    this->index = 0;
}
