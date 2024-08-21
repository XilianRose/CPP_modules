#include "PresidentialPardonForm.hpp"
#include "colours.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5, "default") {
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5, target) {
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
	std::cout << "Copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << GRAY "Destructor called" NC << std::endl;
	return;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->AForm::operator=(src);
	return *this;
}

void	PresidentialPardonForm::action(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}
