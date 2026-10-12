#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("blank name"), _grade(LOWEST_GRADE)
{
	std::cout << "Default Bureaucrat constructor was called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHightException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Bureaucrat custom constructor with (name: " << name << ", grade: " << grade << ") was called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy contructor for" << src._name <<  " was called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat (" << this->_name << ") is destructed" << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < HIGHEST_GRADE)
		throw GradeTooHightException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHightException::what() const noexcept
{
	return "Bureaucrat::Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat::Grade is too low";
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return os;
}