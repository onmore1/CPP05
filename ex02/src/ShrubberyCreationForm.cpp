#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor was called\n";
}


void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	file << "       _-_\n"
		"   /~~     ~~\\\n"
		"  /~~       ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n"
		"  _ -  | |   -_\n"
		"      // \\\\";
	file.close();
}