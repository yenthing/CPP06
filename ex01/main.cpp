#include "Serializer.hpp"

int main()
{
    std::cout << "---Test 1: Valid-------" << std::endl;
    Data data;
    data.n = 1;
    std::strcpy(data.s1, "Hello");
    data.n = 2;
    std::strcpy(data.s2, "World");

    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);

    if (deserialized == &data)
    {
        std::cout << "s1: " << deserialized->s1 << std::endl;
        std::cout << "n: " << deserialized->n << std::endl;
        std::cout << "s2: " << deserialized->s2 << std::endl;
    }
    else
        std::cerr << "Deserialization failed!" << std::endl;
    
    std::cout << "\n---Test 2: NULL POINTER-----" << std::endl;
    Data *nullData = nullptr;
    uintptr_t nullSerialized = Serializer::serialize(nullData);
    Data *nullDeserialized = Serializer::deserialize(nullSerialized);
    if (nullDeserialized == nullptr)
        std::cout << "Deserialization successful!" << std::endl;
    else
        std::cerr << "Deserialization failed!" << std::endl;

    std::cout<< "\n---Test 3: BOUNDARY MIN-----" << std::endl;
    Data data2;
    data2.n = INT_MIN;
    std::strcpy(data2.s1, "Boundary Min");
    serialized = Serializer::serialize(&data2);
    deserialized = Serializer::deserialize(serialized);
    if (deserialized == &data2)
    {
        std::cout << "s1: " << deserialized->s1 << std::endl;
        std::cout << "n: " << deserialized->n << std::endl;
    }
    else
        std::cerr << "Deserialization failed!" << std::endl;
    
    std::cout<< "\n---Test 4: BOUNDARY MAX-----" << std::endl;
    Data data3;
    data3.n = INT_MAX;
    std::strcpy(data3.s2, "Boundary Max");
    serialized = Serializer::serialize(&data3);
    deserialized = Serializer::deserialize(serialized);
    if (deserialized == &data3)
    {
        std::cout << "s2: " << deserialized->s2 << std::endl;
        std::cout << "n: " << deserialized->n << std::endl;
    }
    else
        std::cerr << "Deserialization failed!" << std::endl;

    return 0;
}
