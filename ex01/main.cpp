#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main() {
	Data data;

	data.id = 1;
	data.name = "dummy";
	data.value = 1.1;
    
	std::cout << "Data's original address: " << &data << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << "Serialized data address: 0x" << std::hex << serialized << std::dec << std::endl;
    
 	Data *deserializedData;

	deserializedData = Serializer::deserialize(serialized);

	std::cout << "Deserialized data address: " << deserializedData << std::endl;
    
	std::cout << "\nid: " << deserializedData->id << std::endl 
				<< "name: " << deserializedData->name << std::endl
				<< "value: " << deserializedData->value << std::endl;

    return 0;
}
