#include "Form.hpp"
#include "colours.hpp"

Form::Form(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Form::Form(std::string const & name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
	std::cout << "Parametric constructor called" << std::endl;
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form const & src) : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Form::~Form(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

Form &				Form::operator=(Form const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_signed = src.getSigned();
	return *this;
};

const std::string	Form::getName(void) const{
	return this->_name;
}

bool				Form::getSigned(void) const{
	return this->_signed;
}

int					Form::getSignGrade(void) const{
	return this->_signGrade;
}

int					Form::getExecGrade(void) const{
	return this->_execGrade;
}

void				Form::beSigned(Bureaucrat & src){
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	if (src.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
	return;
}

const char *		Form::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *		Form::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char *		Form::FormAlreadySignedException::what() const throw(){
	return "Form is already signed";
}

std::ostream &		operator<<(std::ostream & out, Form const & src){
	out << "Form " LILAC << src.getName() << NC " is ";
	if (src.getSigned())
		out << LILAC "signed" NC;
	else
		out << LILAC "not signed" NC;
	out << " and requires grade " LILAC << src.getSignGrade() << NC " to sign and grade " LILAC << src.getExecGrade() << NC " to execute";
	return out;
}
