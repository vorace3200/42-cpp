#pragma once

#include <iostream>
#include <string>

class Weapon
{

    public:
        Weapon(const std::string type);
        ~Weapon();
        std::string getType() const;
        void setType(std::string new_type);
        
    private: 
        std::string type;
};
