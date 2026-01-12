#pragma once
#include <iostream>
class AForm;

class Bureaucrat{
	private : 
		const std::string _name;
		int	_grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat & obj);
		Bureaucrat & operator=(Bureaucrat & obj);
		~Bureaucrat();
		const std::string	getName() const ;
		int	getGrade() const;
		class	GradeTooHighException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm& obj);
		void	executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & Bu);

#include "AForm.hpp"
