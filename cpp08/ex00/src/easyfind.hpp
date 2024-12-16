#pragma once
#include <exception>

class ContainerEmptyException : public std::exception{
	public:
		virtual const char * what() const throw(){
			return "Container is empty";
		}
};

class ValueNotFoundException : public std::exception{
	public:
		virtual const char * what() const throw(){
			return "Value not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator current = container.begin();
	typename T::iterator end = container.end();

	if (current == end)
		throw ContainerEmptyException();
	while (current != end){
		if (*current == value)
			return current;
		current++;
	}
	throw ValueNotFoundException();
}
