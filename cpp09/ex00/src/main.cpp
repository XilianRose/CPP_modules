#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"



int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " [<database.txt>]" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	try{
		BitcoinExchange::execute(filename);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}