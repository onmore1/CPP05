#include "../include/AForm.hpp"

AForm::AForm() : _name("default AForm"),  _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE), _isSigned(false)
{
	std::cout << "AForm default contructor was called" << "\n";
}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "AForm custom constructor with (" << name << ", " << signGrade << ", " <<  execGrade << ") was called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned) 
{
	std::cout << "AForm copy contructor for " << src._name << " was called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	std::cout << "AForm '=' operator for: '" << this->_name << "; was called\n";
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm deconstructor for: '" << this->_name << "' was called\n";
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

const std::string AForm::getName() const
{
	return this->_name;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "AForm::Form is not signed";
}

const char *AForm::ExecuteGradeTooLowException::what() const throw()
{
	return "AForm::ExecuteGradeTooLow";
}

void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm &src)
{
	out << "AForm: " << src.getName() << ", " << src.getExecGrade() << ", " << src.getSignGrade() << ", " << src.getIsSigned() << std::endl;
	return out;
}


void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->_execGrade)
		throw AForm::ExecuteGradeTooLowException();
	this->executeAction();
}