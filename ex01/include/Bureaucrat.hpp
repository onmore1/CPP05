#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

enum {HIGHEST_GRADE = 1, LOWEST_GRADE = 150};

class Form;

class Bureaucrat
{
private:
	const	std::string _name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();
	//getters
	const std::string &getName() const;
	int getGrade() const;
	//
	void incrementGrade();
	void decrementGrade();
	//execeptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const noexcept override; //what = reads error message; noexcept = wont throw an exception
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};
	//other
	void signForm(Form &form); //!call from Form::beSigned;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &src);