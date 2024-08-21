#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const & name, unsigned int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat &		operator=(Bureaucrat const & src);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form & src);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src);
