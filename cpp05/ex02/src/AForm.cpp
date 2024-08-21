#include "AForm.hpp"
#include "colours.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150), _target("default"){
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

AForm::AForm(std::string const & name, unsigned int signGrade, unsigned int execGrade, std::string const & target) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade), _target(target){
	std::cout << GRAY "Parametric constructor called" NC << std::endl;
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	return;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

AForm::~AForm(void){
	std::cout << GRAY "Destructor called" NC << std::endl;
	return;
}

AForm &				AForm::operator=(AForm const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_signed = src.getSigned();
	return *this;
};

const std::string	AForm::getName(void) const{
	return this->_name;
}

bool				AForm::getSigned(void) const{
	return this->_signed;
}

int					AForm::getSignGrade(void) const{
	return this->_signGrade;
}

int					AForm::getExecGrade(void) const{
	return this->_execGrade;
}

const std::string	AForm::getTarget(void) const{
	return this->_target;
}

void				AForm::beSigned(Bureaucrat & src){
	if (this->_signed)
		throw AForm::FormAlreadySignedException();
	if (src.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	return;
}

void				AForm::execute(Bureaucrat const & executor) const{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	this->action();
	return;
}

const char *		AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *		AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const char *		AForm::FormAlreadySignedException::what() const throw(){
	return "Form is already signed";
}

const char *		AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed";
}

std::ostream &		operator<<(std::ostream & out, AForm const & src){
	out << "Form " LILAC << src.getName() << NC " is ";
	if (src.getSigned())
		out << LILAC "signed" NC;
	else
		out << LILAC "not signed" NC;
	out << " and requires grade " LILAC << src.getSignGrade() << NC " to sign and grade " LILAC << src.getExecGrade() << NC " to execute";
	return out;
}
