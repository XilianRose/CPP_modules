#include "Intern.hpp"
#include "colours.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
	std::cout << GRAY "Intern default constructor called" NC << std::endl;
	return ;
}

Intern::Intern(Intern const & src) {
	std::cout << GRAY "Intern copy constructor called" NC << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void) {
	std::cout << GRAY "Intern destructor called" NC << std::endl;
	return ;
}

Intern &	Intern::operator=(Intern const & src) {
	std::cout << GRAY "Intern copy assignment operator called" NC << std::endl;
	(void)src;
	return *this;
}

AForm *	Intern::makeForm(std::string const & formName, std::string const & target) {
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm * (Intern::*functions[3])(std::string const & target) = {&Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm, &Intern::createShrubberyCreationForm};

	try{
		for (int i = 0; i < 3; i++) {
			if (formName == formNames[i]) {
				std::cout << GREEN "Intern creates " << formName << " form" NC << std::endl;
				return (this->*functions[i])(target);
			}
		}
		throw Intern::UnknownFormException();
	}
	catch (std::exception & e) {
		std::cerr  << e.what() << RED ". Intern doesn't know how to create " << formName << " form" NC << std::endl;
	}
	return NULL;
}

AForm *	Intern::createShrubberyCreationForm(std::string const & target) {
	return new ShrubberyCreationForm(target);
}

AForm *	Intern::createRobotomyRequestForm(std::string const & target) {
	return new RobotomyRequestForm(target);
}

AForm *	Intern::createPresidentialPardonForm(std::string const & target) {
	return new PresidentialPardonForm(target);
}

const char *	Intern::UnknownFormException::what() const throw() {
	return RED "Unknown form" NC;
}
