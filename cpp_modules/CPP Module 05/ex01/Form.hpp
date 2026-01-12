#pragma once
#include <iostream> // IWYU pragma: keep
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string _name;
		const int 	_grade;
		bool	_isSigned;
		const int 	_gradeForSign;
	public :
		Form();
		Form(std::string name, int grade, int gradeForSign);
		Form(Form & obj);
		Form & operator=(Form & obj);
		~Form();
		std::string getName() const;
		int	getGrade() const;
		bool	getIsSigned() const;
		int	getGradeForSign() const;
		class	GradeTooHighException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		bool beSigned(Bureaucrat& Bu);
};

std::ostream& operator<<(std::ostream& os, const Form& Fo);