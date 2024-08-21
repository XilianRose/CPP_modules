#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colours.hpp"

int	main(){
	try {
		std::cout << CYAN "	~	Creating Bureaucrats and Forms	~	" NC << std::endl;
		Bureaucrat Bob("Bob", 1);
		Bureaucrat Cat("Cat", 146);
		ShrubberyCreationForm FormA("ShrubberyCreationForm");
		RobotomyRequestForm FormB("RobotomyRequestForm");
		PresidentialPardonForm FormC("PresidentialPardonForm");

		std::cout << std::endl << Bob << std::endl;
		std::cout << Cat << std::endl << std::endl;

		std::cout << CYAN "	~	Signing and executing ShrubberyCreationForm	~	" NC << std::endl;
		std::cout << FormA << std::endl;
		Cat.signForm(FormA);
		Cat.incrementGrade();
		Cat.signForm(FormA);
		std::cout << FormA << std::endl;
		Cat.executeForm(FormA);
		Bob.signForm(FormA);
		Bob.executeForm(FormA);
		std::cout << FormA << std::endl << std::endl;

		std::cout << CYAN "	~	Signing and executing RobotomyRequestForm	~	" NC << std::endl;
		std::cout << FormB << std::endl;
		Bob.signForm(FormB);
		std::cout << FormB << std::endl << std::endl;
		for (int i = 0; i < 10; i++)
			Bob.executeForm(FormB);

		std::cout << std::endl << CYAN "	~	Signing and executing PresidentialPardonForm	~	" NC << std::endl;
		std::cout << FormC << std::endl;
		Bob.signForm(FormC);
		std::cout << FormC << std::endl;
		Bob.executeForm(FormC);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}
