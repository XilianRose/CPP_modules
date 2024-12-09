#include "Serializer.hpp"
#include "colours.hpp"
#include <iostream>

int	main(void){
	Data originalData = {"Hello", 42};
	uintptr_t raw = Serializer::serialize(&originalData);
	Data* deserializedData = Serializer::deserialize(raw);

	if (deserializedData == &originalData) {
		std::cout << GREEN "Serialization and deserialization successful!" NC<< std::endl;
		std::cout << "Original Data:		n = " << originalData.n << ", str = " << originalData.str << std::endl;
		std::cout << "Serialized data:	" << raw << std::endl;
		std::cout << "Deserialized Data:	n = " << deserializedData->n << ", str = " << deserializedData->str << std::endl;
	} else
		std::cerr << "Error: Pointers do not match!" << std::endl;
	return 0;
}
