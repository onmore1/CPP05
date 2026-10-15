#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor was called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm custom constructor was called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor was called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm copy assignment operator was called\n";
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor was called\n";
}

void RobotomyRequestForm::executeAction() const
{
	static bool shouldSucceed = true;
	std::cout << "Brrrrrr... drilling noises..." << std::endl;
	if (shouldSucceed)
	{
		std::cout << this->_target << " has been robotomized successfully" << std::endl;	
		shouldSucceed = false;
	}
	else
	{
		std::cout << "The robotomy of " << this->_target << " failed" << std::endl;
		shouldSucceed = true;
	}
}