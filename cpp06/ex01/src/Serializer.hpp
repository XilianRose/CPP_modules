#pragma once
#include <cstdint>
#include <string>

struct Data{
	std::string		str;
	int				n;
};

class Serializer {
	public:
		Serializer(void) = delete;
		Serializer(Serializer const & src) = delete;
		virtual	~Serializer(void) = delete;

		Serializer &	operator=(Serializer const & src) = delete;

		static uintptr_t		serialize(Data * ptr);
		static Data *			deserialize(uintptr_t raw);
};
