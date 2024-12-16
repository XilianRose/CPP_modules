#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>
#include "colours.hpp"

int main(){
	{
		std::list<int> empty;
		std::list<int> lst;
		int value = 5;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);
		std::cout << BOLD << "Searching for " << value << " in the empty int list..." << NC << std::endl;
		try {
			auto it = easyfind(empty, value);
			std::cout << GREEN << "Value found: " << *it << NC << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
		std::cout << BOLD << "Searching for " << value << " in the int list..." << NC << std::endl;
		try {
			auto it = easyfind(lst, value);
			std::cout << GREEN << "Value found: " << *it << NC << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
	}
	{
		std::vector<int> vec;
		int value = 3;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		
		std::cout << BOLD << "Searching for " << value << " in the int vector..." << NC << std::endl;
		try {
			auto it = easyfind(vec, value);
			std::cout << GREEN << "Value found: " << *it << NC << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << NC << std::endl;
		}
	}
	return 0;
}