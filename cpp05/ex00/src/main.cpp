#include "Bureaucrat.hpp"
#include "colours.hpp"

int	main(){
	{
		std::cout << BOLD UNDERLINE "\n	Basic tests" NC << std::endl;
		Bureaucrat a = Bureaucrat("Arno", 1);
		Bureaucrat b = Bureaucrat("Bob", 150);
		Bureaucrat c = Bureaucrat("Cathy", 100);
		// Bureaucrat d = Bureaucrat("Daisy", 160);

		// std::cout << a << std::endl;
		// a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		// b.decrementGrade();
		// std::cout << b << std::endl;

		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;

		std::cout << GRAY << a << std::endl;
		std::cout << c << std::endl;
		c = a;
		std::cout << a << std::endl;
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << a << std::endl;
		std::cout << c << NC << std::endl;
	}
	{
		try	{
			std::cout << BOLD UNDERLINE "\n	Tests w/ try and catch" NC << std::endl;
			Bureaucrat a = Bureaucrat("Arno", 1);
			Bureaucrat b = Bureaucrat("Bob", 150);
			Bureaucrat c = Bureaucrat("Cathy", 100);
			// Bureaucrat d = Bureaucrat("Daisy", 160);

			// std::cout << a << std::endl;
			// a.incrementGrade();
			std::cout << a << std::endl;
			a.decrementGrade();
			std::cout << a << std::endl;

			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			// b.decrementGrade();
			// std::cout << b << std::endl;

			std::cout << c << std::endl;
			c.incrementGrade();
			std::cout << c << std::endl;
			c.decrementGrade();
			std::cout << c << std::endl;

			std::cout << GRAY << a << std::endl;
			std::cout << c << std::endl;
			c = a;
			std::cout << a << std::endl;
			std::cout << c << std::endl;
			c.incrementGrade();
			std::cout << a << std::endl;
			std::cout << c << NC << std::endl;
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
	}
}
