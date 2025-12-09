#include "Serializer.hpp"

int main()
{
    Data myData("Test Data", 42);

    std::cout << "Original Data address: " << &myData << std::endl;
    std::cout << "Original Data name: " << myData.name << std::endl;
    std::cout << "Original Data value: " << myData.value << std::endl;

    uintptr_t serialized = Serializer::serialize(&myData);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;

    if (deserialized == &myData)
    {
        std::cout << "Comparison successful: Pointers match." << std::endl;
        std::cout << "Deserialized Data name: " << deserialized->name << std::endl;
        std::cout << "Deserialized Data value: " << deserialized->value << std::endl;
    }
    else
    {
        std::cout << "Comparison failed: Pointers do not match." << std::endl;
    }

    return 0;
}
