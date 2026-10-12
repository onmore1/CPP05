#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cassert>
#include <sstream>

template <typename Action>
static std::string captureOutput(Action action)
{
	std::ostringstream output;
	std::streambuf *original = std::cout.rdbuf(output.rdbuf());
	action();
	std::cout.rdbuf(original);
	return output.str();
}

static std::string signAndCapture(Bureaucrat &bureaucrat, Form &form)
{
	return captureOutput([&bureaucrat, &form]() { bureaucrat.signForm(form); });
}

int main()
{
	int assignedGrade = 0;
	std::string bureaucratLogs = captureOutput([&assignedGrade]() {
		Bureaucrat defaultBureaucrat;
		Bureaucrat source("Source", 10);
		Bureaucrat copied(source);
		Bureaucrat assigned("Assigned", 20);
		assigned = source;
		assignedGrade = assigned.getGrade();
	});
	assert(bureaucratLogs == "Default Bureaucrat constructor was called\n"
		"Bureaucrat custom constructor with (name: Source, grade: 10) was called\n"
		"Bureaucrat copy contructor forSource was called\n"
		"Bureaucrat custom constructor with (name: Assigned, grade: 20) was called\n"
		"Bureaucrat (Assigned) is destructed\n"
		"Bureaucrat (Source) is destructed\n"
		"Bureaucrat (Source) is destructed\n"
		"Bureaucrat (blank name) is destructed\n");
	assert(assignedGrade == 10);

	bool assignedFormSigned = false;
	std::string formLogs = captureOutput([&assignedFormSigned]() {
		Form defaultForm;
		Form source("Source", 20, 30);
		Form copied(source);
		Form assigned("Assigned", 40, 50);
		Bureaucrat signer("Signer", 1);
		source.beSigned(signer);
		assigned = source;
		assignedFormSigned = assigned.getIsSigned();
	});
	assert(formLogs == "Form default contructor was called\n"
		"Form custom constructor with (Source, 20, 30) was called\n"
		"Form copy contructor for Source was called\n"
		"Form custom constructor with (Assigned, 40, 50) was called\n"
		"Bureaucrat custom constructor with (name: Signer, grade: 1) was called\n"
		"Form '=' operator for: 'Assigned; was called\n"
		"Bureaucrat (Signer) is destructed\n"
		"Form deconstructor for: 'Assigned' was called\n"
		"Form deconstructor for: 'Source' was called\n"
		"Form deconstructor for: 'Source' was called\n"
		"Form deconstructor for: 'default form' was called\n");
	assert(assignedFormSigned);

	Bureaucrat qualified("Alice", 75);
	Form successfulForm("Permit", 75, 100);
	assert(signAndCapture(qualified, successfulForm) == "Alice signed Permit\n");
	assert(successfulForm.getIsSigned());

	Bureaucrat underqualified("Bob", 76);
	Form rejectedForm("License", 75, 100);
	assert(signAndCapture(underqualified, rejectedForm)
		== "Bob couldn't sign License because Form::GradeTooLowException\n");
	assert(!rejectedForm.getIsSigned());
	return 0;
}