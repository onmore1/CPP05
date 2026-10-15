#include "../include/Form.hpp"

Form::Form() : _name("default form"),  _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE), _isSigned(false)
{
	std::cout << "Form default constructor was called\n";
}

Form::Form(const std::string &name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Form custom constructor with (" << name << ", " << signGrade << ", " <<  execGrade << ") was called" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned) 
{
	std::cout << "Form copy contructor for " << src._name << " was called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	std::cout << "Form '=' operator for: '" << this->_name << "; was called\n";
	return *this;
}

Form::~Form()
{
	std::cout << "Form deconstructor for: '" << this->_name << "' was called\n";
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

const std::string Form::getName() const
{
	return this->_name;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return "Form::GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "Form::GradeTooLowException";
}

const char *Form::FormAlreadysigned::what() const noexcept
{
	return "Form::AlreadySigned";
}

void Form::beSigned(const Bureaucrat &src)
{
	if (this->_isSigned)
		throw Form::FormAlreadysigned();
	if (src.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form &src)
{
	out << "Form: (Name: '" << src.getName() << "'; Execution grade: '" << src.getExecGrade() << "'; Sign grade: '" << src.getSignGrade() << "'; Status: '";
	if (src.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << "'" << std::endl;
	return out;
}