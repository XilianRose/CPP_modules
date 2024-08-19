#pragma once
#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const & name, unsigned int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat &		operator=(Bureaucrat const & src);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

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
		int					_grade;
};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src);
