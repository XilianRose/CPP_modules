#include "Bureaucrat.hpp"
#include "colours.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150){
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade) : _name(name), _grade(grade){
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade()){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << GRAY "Destructor called" NC << std::endl;
	return;
}

Bureaucrat &		Bureaucrat::operator=(Bureaucrat const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_grade = src.getGrade();
	return *this;
};

const std::string	Bureaucrat::getName(void) const{
	return this->_name;
}

unsigned int		Bureaucrat::getGrade(void) const{
	return this->_grade;
}

void				Bureaucrat::incrementGrade(void){
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void				Bureaucrat::decrementGrade(void){
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::signForm(AForm & src){
	try{
		src.beSigned(*this);
		std::cout << GRAY << this->_name << " signed " << src.getName() << NC << std::endl;
	}
	catch (std::exception & e){
		std::cout << GRAY << this->_name << " couldn't sign " << src.getName() << " because " << e.what() << NC << std::endl;
	}
}

void				Bureaucrat::executeForm(AForm const & src){
	try{
		src.execute(*this);
		std::cout << GRAY << this->_name << " executed " << src.getName() << NC << std::endl;
	}
	catch (std::exception & e){
		std::cout << GRAY << this->_name << " couldn't execute " << src.getName() << " because " << e.what() << NC << std::endl;
	}
}

const char *		Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *		Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

std::ostream &		operator<<(std::ostream & out, Bureaucrat const & src){
	return (out << src.getName() << ", bureaucrat grade " << src.getGrade());
}
