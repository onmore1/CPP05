#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
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