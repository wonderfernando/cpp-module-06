#include "Serializer.hpp"

int main(void)
{
    // Create a Data object
    Data data;
    data.name = "Data Fernado";

    std::cout << "Endereço: " << &data << std::endl;
    std::cout << "Nome: " << data.name << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
 
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << std::endl;

    std::cout << "Endereço da deserialização: " << deserialized << std::endl;
    std::cout << "Endereço de data: " << &data << std::endl;

    std::cout << "================================" << std::endl;
    Data* teste = Serializer::deserialize(Serializer::serialize(&data));
    std::cout << teste->name << std::endl;
    return (0);
}