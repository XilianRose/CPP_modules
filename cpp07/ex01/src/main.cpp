#include <iostream>
#include "iter.hpp"
#include "colours.hpp"


template <typename T>
static void print(T & element){
	std::cout << element << std::endl;
}

template <typename T>
static void timesTwo(T & element){
	element = element + element;
}


int main(){
	{
		int intArray[] = {1, 2, 3, 4, 5};
		std::cout << LILAC "Original intArray:" NC << std::endl;
		iter(intArray, 5, print);
		iter(intArray, 5, timesTwo);
		std::cout << LILAC "intArray after timesTwo:" NC << std::endl;
		iter(intArray, 5, print);
	}
	{
		std::string stringArray[] = {"one", "two", "three", "four", "five"};
		std::cout << LILAC "Original stringArray:" NC << std::endl;
		iter(stringArray, 5, print);
		iter(stringArray, 5, timesTwo);
		std::cout << LILAC "stringArray after timesTwo:" NC << std::endl;
		iter(stringArray, 5, print);
	}
	return 0;
}
