/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 14:46:09 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/21 18:06:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(std::string filename, std::string s1, std::string s2){
	std::ifstream	originalFile(filename);
	std::ofstream	newFile(filename.append(".replace"));
	std::string		input;
	int				pos;
	char			c;


	if (!originalFile){
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}
	if (!newFile){
		std::cerr << "Unable to create file" << std::endl;
		return 1;
	}
	while (std::getline(originalFile, input)){
		pos = input.find(s1);
		if (pos != std::string::npos){
			for (int i = 0; i < pos; i++){
				newFile << input[i];
			}
			newFile << s2;
		}
		// left off here

		// if (input.compare(s1) == 0)
		// 	newFile << s2;
		// else
		// 	newFile << input;
		// originalFile.get(c);
		// newFile << c;
	}
	return 0;
}

int	main(int argc, char** argv){
	std::ofstream	newFile;
	std::string		filename;

	if (argc != 4){
		std::cerr << "Invalid input. Usage: <filename> <string> <string>" << std::endl;
		return 1; 
	}
	if (replace(argv[1], argv[2], argv[3]) == 1)
		return 1;
	return 0;
}
