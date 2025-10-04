#pragma once

#include <iostream>
#include <string>

class Weapon
{

    public:
        Weapon(const std::string type);
        ~Weapon();
        std::string getType();
        void setType(std::string new_type);
        
    private: 
        std::string type;
};
