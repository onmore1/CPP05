#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		const int	_signGrade;
		const int	_execGrade;
		bool		_isSigned;
		public:
		Form();
		Form(const std::string &name, const int signGrade, const int execGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();
	//getters
		int	getSignGrade() const;
		int	getExecGrade() const;
		bool getIsSigned() const;
		const std::string getName() const;
	//execeptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};
	//other
	void beSigned(const Bureaucrat &src);
};

std::ostream &operator<<(std::ostream &out, const Form &src);