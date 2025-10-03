#include <iostream>
#include <fstream>
#include <string>
#include <iterator>


int main(int a, char **b) {
    if (a != 4)
    {
        std::cout << "please provide s1 and s2 (filename)" << std::endl;
        return 1;
    }
    std::string filename = std::string(b[1]);
    std::string s1 = std::string(b[2]);
    std::string s2 = std::string(b[3]);
    
    if (s1.empty())
    {
        std::cout << "s1 can't be empty." << std::endl;
        return 1;
    }

    std::ifstream file_handle(filename.c_str(), std::ios::in | std::ios::binary);
    if (!file_handle)
    {
        std::cout << "File not found : " << filename << std::endl;
        return 1;
    }

    std::string file_content((std::istreambuf_iterator<char>(file_handle)), (std::istreambuf_iterator<char>())); // std::istreambuf_iterator -> Iterrateur qui permet de lire caractere par caractere dans le flux.
    if(file_content.empty())
    {
        std::cout << "File cannot be empty " << filename << std::endl;
        return 1;
    }
    
    size_t pos = file_content.find(s1);
    while (pos != std::string::npos)
    {
        file_content.erase(pos, s1.size());
        file_content.insert(pos, s2);
        pos = file_content.find(s1, pos + s2.size());
    }


    std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
    out << file_content;
    out.close();

    return 0;
}