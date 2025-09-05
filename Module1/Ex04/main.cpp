#include <iostream>
#include <fstream>
#include <string>

std::string check(const std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\\' && i + 1 < str.length()) {
            switch (str[i + 1]) {
                case 'n': 
                    result += '\n'; i++; break;
                case 't': 
                    result += '\t'; i++; break;
                case 'r': 
                    result += '\r'; i++; break;
                case '\\': 
                    result += '\\'; i++; break;
                default: 
                    result += str[i]; break;
            }
        } else {
            result += str[i];
        }
    }
    return result;
}

int main(int a, char **b) {
    if (a != 4)
    {
        std::cout << "please provide s1 and s2 (filename)" << std::endl;
        return 1;
    }
    std::string filename = std::string(b[1]);
    std::string s1 = check(std::string(b[2]));
    std::string s2 = check(std::string(b[3]));
    
    if (s1.empty())
    {
        std::cout << "s1 can't be empty." << std::endl;
        return 1;
    }

    std::ifstream file_handle(filename);
    if (!file_handle)
    {
        std::cout << "File not found : " << filename << std::endl;
        return 1;
    }
    file_handle.seekg(0, std::ios::end); 
    size_t size = file_handle.tellg(); 
    file_handle.seekg(0); 
    
    std::string content(size, '\0'); 
    file_handle.read(&content[0], size);
    size_t pos = content.find(s1);
    while (pos != std::string::npos)
    {
        content.erase(pos, s1.size());

        content.insert(pos, s2);
        pos = content.find(s1, pos + s2.size());
    }

    std::ofstream file_replace(filename + ".replace");
    file_replace << content;
    file_replace.close();

    return 0;
}