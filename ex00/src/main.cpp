#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat customBureaucrat("custom", 1);
		std::cout << customBureaucrat;
		customBureaucrat.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}	
	std::cout << "------------------------------\n";
	try
	{
		Bureaucrat customBureaucrat("custom", 150);
		std::cout << customBureaucrat;
		customBureaucrat.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat;
		std::cout << "------------------------------\n";
		std::cout << bureaucrat.getGrade() << "\n";
		std::cout << bureaucrat.getName() << "\n";
		std::cout << "------------------------------\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat2("", -1);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}