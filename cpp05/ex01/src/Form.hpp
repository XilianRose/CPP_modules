#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string const & name, unsigned int signGrade, unsigned int execGrade);
		Form(Form const & src);
		~Form(void);

		Form &				operator=(Form const & src);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void				beSigned(Bureaucrat & src);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class FormAlreadySignedException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
};

std::ostream &	operator<<(std::ostream & out, Form const & src);
