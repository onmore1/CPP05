#pragma once


#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm{
	private:
		const std::string _name;
		const int	_signGrade;
		const int	_execGrade;
		bool		_isSigned;
		public:
		AForm();
		AForm(const std::string &name, const int signGrade, const int execGrade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();
	//getters
		int	getSignGrade() const;
		int	getExecGrade() const;
		bool getIsSigned() const;
		const std::string getName() const;
	//execeptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class ExecuteGradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	//other
	void beSigned(const Bureaucrat &src);
	protected:
	virtual void executeAction() const = 0;
	public:
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &src);
