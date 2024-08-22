#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "colours.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137, "default"){
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137, target){
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << GRAY "Destructor called" NC << std::endl;
	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->AForm::operator=(src);
	return *this;
}

void	ShrubberyCreationForm::action(void) const{
	std::ofstream file;

	file.open(this->getTarget() + "_shrubbery");
	if (!file.is_open()){
		std::cerr << "Couldn't open file" << std::endl;
		return ;
	}


	file << "          # #### ####           " << std::endl;
	file << "        ### \\/#|### |/####      " << std::endl;
	file << "       ##\\/#/ \\||/##/_/##/_#    " << std::endl;
	file << "     ###  \\/###|/ \\/ # ###      " << std::endl;
	file << "   ##_\\_#\\_\\## | #/###_/_####   " << std::endl;
	file << "  ## #### # \\ #| /  #### ##/##  " << std::endl;
	file << "   __#_--###`  |{,###---###-~   " << std::endl;
	file << "             \\ }{               " << std::endl;
	file << "              }}{               " << std::endl;
	file << "              }}{               " << std::endl;
	file << "              {{}               " << std::endl;
	file << std::endl;
	file.close();
	return ;
}
