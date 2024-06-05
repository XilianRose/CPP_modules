/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 14:46:09 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/05 13:01:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(std::string filename, std::string s1, std::string s2, int newLines){
	std::ifstream	originalFile(filename);
	std::ofstream	newFile(filename.append(".replace"));
	std::string		input;
	size_t			pos;

	if (!originalFile){
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}
	if (!newFile){
		std::cerr << "Unable to create file" << std::endl;
		return 1;
	}
	for (int i = 0; std::getline(originalFile, input); i++){
		pos = 0;
		while (1){
			pos = input.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			input.erase(pos, s1.length());
			input.insert(pos, s2);
			// input.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		newFile << input;
		if (i < newLines)
			newFile << std::endl;
	}
	return 0;
}

int	countNewlines(std::string filename){
	std::ifstream	infile(filename);
	char			c;
	int				count = 0;

	if (!infile){
		std::cerr << "Unable to open file" << std::endl;
		infile.close();
		return -1;
	}
	while(infile.get(c)){
		if (c == '\n')
			count++;
	}
	infile.close();
	return count;
}


int	main(int argc, char** argv){
	std::ofstream	newFile;
	std::string		s1;
	int				newLines;

	if (argc != 4){
		std::cerr << "Invalid input. Usage: <filename> <string 1> <string 2>" << std::endl;
		return 1; 
	}
	s1 = argv[2];
	if (s1 == ""){
		std::cerr << "Invalid input. String 1 can't be empty" << std::endl;
		return 1;
	}
	newLines = countNewlines(argv[1]);
	if (newLines < 0)
		return 1;
	if (replace(argv[1], argv[2], argv[3], newLines) == 1)
		return 1;
	return 0;
}
