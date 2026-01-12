#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string _name;
		const int 	_grade;
		bool	_isSigned;
		const int 	_gradeForSign;
	public :
		AForm();
		AForm(std::string name, int grade, int gradeForSign);
		AForm(AForm & obj);
		AForm & operator=(AForm & obj);
		virtual ~AForm();
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
		class	FormNotExecutedException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
		bool beSigned(Bureaucrat& Bu);
		virtual void	execute(Bureaucrat const & executor)  const  = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& Fo);