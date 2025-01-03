#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"
#include "colours.hpp"



int	main(int argc, char **argv)
{
	BitcoinExchange bitcoinExchange;
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " [<database.txt>]" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	try{
		bitcoinExchange.execute(filename);
	}
	catch (std::exception &e){
		std::cerr << RED << e.what() << NC << std::endl;
		return 1;
	}
	return 0;
}
