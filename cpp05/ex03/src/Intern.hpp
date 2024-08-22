#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern {
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern &	operator=(Intern const & src);

		AForm *	makeForm(std::string const & formName, std::string const & target);
		AForm *	createShrubberyCreationForm(std::string const & target);
		AForm *	createRobotomyRequestForm(std::string const & target);
		AForm *	createPresidentialPardonForm(std::string const & target);

		class UnknownFormException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};
