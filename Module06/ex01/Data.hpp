#pragma once
#include <iostream>
#include <string>

struct Data
{
    std::string name;
    int value;
    Data(std::string n, int v) : name(n), value(v) {}
};
