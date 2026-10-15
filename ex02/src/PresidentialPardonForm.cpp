#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor was called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm custom constructor was called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor was called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm copy assignment operator was called\n";
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor was called\n";
}


void PresidentialPardonForm::executeAction() const 
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}