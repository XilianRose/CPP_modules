#include "RobotomyRequestForm.hpp"
#include "colours.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45, "default"){
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45, target){
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << GRAY "Destructor called" NC << std::endl;
	return;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->AForm::operator=(src);
	return *this;
}

void	RobotomyRequestForm::action(void) const {
	std::cout << ITALIC "* drilling noises *" NC << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
	return ;
}
