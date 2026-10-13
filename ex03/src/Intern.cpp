#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "Inter default constructor was called\n";
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor was called\n";
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Intern assignment operator was called\n";
	return *this;
}

Intern::~Intern()
{
	std::cout << "Inter destructor was called\n";
}

static AForm *makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	static AForm *(*functions[6])(const std::string &target) = {makeRobotomy, makePresidential, makeShrubbery, makeShrubbery, makeRobotomy, makePresidential};
	std::string formsList[6] = {"robotomy request", "presidential pardon", "shrubbery creation", "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 6; i++)
	{
		if(formName == formsList[i])
		{
			std::cout << "Intern creates: " << formName << "\n";
			return (functions[i](formTarget));
		}
	}
	std::cout << "Unable to create: '" << formName << "'. No such type of form\n";
	std::cout << "**Available types: ";
	for (int i = 0; i < 3; i++)
	{
		if (i < 2)
			std::cout << formsList[i] << ", ";
		else
			std::cout << formsList[i] << ";" << std::endl;
	}
	return (NULL);	
};