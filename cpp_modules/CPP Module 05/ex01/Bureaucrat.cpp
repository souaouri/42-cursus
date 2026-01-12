#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat & obj)
{
	*this = obj;
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat & obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}
const std::string	Bureaucrat::getName() const
{
	return _name;
}
int	Bureaucrat::getGrade() const
{
	return _grade;
}
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& obj)
{
	try
	{
		if (obj.beSigned(*this) == false)
		{
			std::string e = this->_name +  " couldn’t sign " + obj.getName() + " because " + "grade Not suitable";
			throw e;
		}
		std::cout <<  this->_name +  " signed " + obj.getName() << std::endl;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat & Bu)
{
	os << Bu.getName() << ", bureaucrat grade " << Bu.getGrade() << "." << std::endl;
	return os;
}