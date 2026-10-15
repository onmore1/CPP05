#pragma once
#include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		 PresidentialPardonForm(const std::string &target);
		 PresidentialPardonForm();
		 PresidentialPardonForm(const  PresidentialPardonForm &src);
		 PresidentialPardonForm &operator=(const  PresidentialPardonForm &src);
		~PresidentialPardonForm();
		void executeAction() const;
};

