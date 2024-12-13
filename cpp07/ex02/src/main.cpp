#include "Array.hpp"

#define MAX_VAL 3

template <typename T>
static void print(T & element){
	std::cout << element << std::endl;
}

template <typename T>
static void	iter(T * address, size_t length, void (*f)(T &)){
	if (!address || !f || length <= 0)
		return;
	for (size_t i = 0; i < length; i++){
		f(address[i]);
	}
}

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << LILAC "Numbers array: " NC << std::endl;
	iter(numbers.getArray(), numbers.getSize(), print);
	std::cout << LILAC "Mirror array: " NC << std::endl;
	iter(mirror, MAX_VAL, print);
	
	/* testing copies*/
	{
		std::cout << MAGENTA "~   Test copy constructor   ~" NC << std::endl;
		Array<int> tmp;
		tmp = numbers;
		std::cout << MAGENTA "original temp array (by assignment operator): " NC << std::endl;
		iter(tmp.getArray(), tmp.getSize(), print);
		Array<int> test(tmp);
		std::cout << MAGENTA "original test array (by copy constructor): " NC << std::endl;
		iter(test.getArray(), test.getSize(), print);
		try{
			test[MAX_VAL - 1] = 0;
			tmp[0] = 0;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << MAGENTA "temp array after adjustment: " NC << std::endl;
		iter(tmp.getArray(), tmp.getSize(), print);
		std::cout << MAGENTA "test array after adjustment: " NC << std::endl;
		iter(test.getArray(), test.getSize(), print);
		std::cout << MAGENTA "Numbers array: " NC << std::endl;
		iter(numbers.getArray(), numbers.getSize(), print);
	}
	std::cout << CYAN "~   Compare arrays   ~" NC << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
		else{
			std::cout << "mirror[" << i << "] == numbers[" << i << "]" << std::endl;
		}
	}
	std::cout << GREEN "~   Test exception   ~" NC << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << LILAC "Numbers array: " NC << std::endl;
	iter(numbers.getArray(), numbers.getSize(), print);
	std::cout << LILAC "Mirror array: " NC << std::endl;
	iter(mirror, MAX_VAL, print);
	delete [] mirror;//
	return 0;
}