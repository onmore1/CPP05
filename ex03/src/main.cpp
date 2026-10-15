#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
int main()
{
	try
	{
		Bureaucrat bureaucrat("test", 136);
		ShrubberyCreationForm shrubbery("file");
		RobotomyRequestForm robotomy("Bender");
		bureaucrat.signForm(shrubbery);
		bureaucrat.executeForm(shrubbery);
		bureaucrat.signForm(robotomy);
		bureaucrat.executeForm(robotomy);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << "CREATING LOW SCORE----------------------------------------------------\n";
	Bureaucrat low_scored("low_scored", 150);
	ShrubberyCreationForm shrubbery("testFile");
	RobotomyRequestForm robotomy("robotomy");
	PresidentialPardonForm presidential("HELLO");
	std::cout << "TESTING LOW SCORE----------------------------------------------------\n";
	low_scored.executeForm(shrubbery);
	low_scored.executeForm(robotomy);
	low_scored.executeForm(presidential);
	std::cout << "CREATING HIGH SCORE----------------------------------------------------\n";
	Bureaucrat high_score("high_scored", 1);
	std::cout << "TESTING HIGHSCORE (forms not signed)----------------------------------------------------\n";
	high_score.executeForm(shrubbery);
	high_score.executeForm(robotomy);
	high_score.executeForm(presidential);
	std::cout << "HIGH SCORE SIGNING FORMS----------------------------------------------------\n";
	high_score.signForm(shrubbery);
	high_score.signForm(robotomy);
	high_score.signForm(presidential);
	std::cout << "TESTING HIGHSCORE (signed forms)----------------------------------------------------\n";
	high_score.executeForm(shrubbery);
	high_score.executeForm(robotomy);
	high_score.executeForm(presidential);
	std::cout << "CREATING INTERN----------------------------------------------------\n";
	Intern intern;
	std::cout << "TESTING INTERN(valid forms)----------------------------------------------------\n";
	AForm *pForm;
	pForm =  intern.makeForm("presidential pardon", "someOne");
	if (pForm)
	{
		high_score.signForm(*pForm);
		high_score.executeForm(*pForm);
		delete pForm;
	}
	std::cout << "TESTING INTERN(INvalid forms)----------------------------------------------------\n";
	pForm = intern.makeForm("presidential nodrap", "bad");
	delete pForm;
	std::cout << "----------------------------------------------------\n";
	return (0);
}