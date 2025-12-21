#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]);
}

static bool isInt(const std::string& literal) {
    char* end;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0') return false;
    return val >= INT_MIN && val <= INT_MAX;
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    if (literal.find('f') == std::string::npos) return false;
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(std::string literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    
    bool impossibleChar = false;
    bool impossibleInt = false;

    if (isChar(literal)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }

    else if (isInt(literal)) {

        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        impossibleChar = (i < 0 || i > 255); 
    }

    else if (isFloat(literal)) {

        f = std::strtof(literal.c_str(), NULL);
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(f);

        if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
            impossibleChar = true;
            impossibleInt = true;
        } 
        else 
        {
            impossibleChar = (f < 0.0f || f > 255.0f);

            if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN)) 
                impossibleInt = true;
        }
    }

    else if (isDouble(literal)) {

        d = std::strtod(literal.c_str(), NULL);
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(d);

        if (literal == "nan" || literal == "+inf" || literal == "-inf") {
            impossibleChar = true;
            impossibleInt = true;
        } else {

            impossibleChar = (d < 0.0 || d > 255.0);

            if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN)) 
                impossibleInt = true;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (impossibleChar)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (impossibleInt)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
