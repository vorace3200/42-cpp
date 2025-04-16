#include <iostream>
#include <string>
#include <iomanip>
class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void set_informations(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        std::string get_informations(int choice);
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    
    public:
        void add_contact(Contact contact);
        void search_contact();
        PhoneBook();
};

