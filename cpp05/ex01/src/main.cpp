#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colours.hpp"

int	main(){
	try {
		Bureaucrat Bob("Bob", 1);
		Bureaucrat Cat("Cat", 150);
		Form FormA("Form A", 149, 1);
		Form FormB("Form B", 149, 1);

		std::cout << GRAY << Bob << NC << std::endl;
		std::cout << GRAY << Cat << NC << std::endl;
		std::cout << FormA << std::endl;
		std::cout << FormB << std::endl;

		Cat.signForm(FormA);
		std::cout << FormA << std::endl;
		Bob.signForm(FormA);
		std::cout << FormA << std::endl;
		Cat.incrementGrade();
		std::cout << GRAY << Cat << NC << std::endl;
		Cat.signForm(FormA);
		Cat.signForm(FormB);
		std::cout << FormB << std::endl;

	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}
