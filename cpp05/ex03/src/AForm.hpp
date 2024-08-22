#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(void);
		AForm(std::string const & name, unsigned int signGrade, unsigned int execGrade, std::string const & target);
		AForm(AForm const & src);
		virtual ~AForm(void);

		AForm &				operator=(AForm const & src);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		const std::string	getTarget(void) const;

		void				beSigned(Bureaucrat & src);
		void				execute(Bureaucrat const & executor) const;
		virtual void		action(void) const = 0;

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

		class FormNotSignedException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
		const std::string	_target;
};

std::ostream &	operator<<(std::ostream & out, AForm const & src);
