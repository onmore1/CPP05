#include "Form.hpp"
int main()
{
	try
	{
		Form testForm("test", 1, 1);
		std::cout << testForm;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("test", 160, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("test", -1, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("test", 1, 160);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("test", 1, -1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm;
		Form testForm2("testForm2", 150, 150);
		std::cout << testForm2;
		testForm2 = testForm;
		std::cout << testForm2;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm;
		Form testForm2(testForm);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("broken", -1, -1);
		Form testForm2(testForm);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("testForm", 75, 75);
		Bureaucrat testBureaucrat("testBureaucrat", 1);
		testBureaucrat.signForm(testForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "-----------------\n";
	//------------------------------------------------------------------------
	try
	{
		Form testForm("testForm", 75, 75);
		Bureaucrat testBureaucrat("testBureaucrat", 76);
		testBureaucrat.signForm(testForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}