#pragma once

#include <iostream>
#include <string>
#include "animal.hpp"
class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);

        const std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);

    private:
      std::string ideas[100];

};