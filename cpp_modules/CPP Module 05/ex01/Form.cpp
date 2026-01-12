#include "Form.hpp"

Form::Form() : _name("default"), _grade(150), _gradeForSign(150)
{
}

Form::Form(std::string name, int grade, int gradeForSign) : _name(name), _grade(grade), _isSigned(0), _gradeForSign(gradeForSign)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

Form::Form(Form & obj) :  _name("default"), _grade(150), _gradeForSign(150)
{
	*this = obj;
}
Form & Form::operator=(Form & obj)
{
	if (this != &obj)
		this->_isSigned = obj._isSigned;
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return _name;
}

int	Form::getGrade() const
{
	return _grade;
}

bool	Form::getIsSigned() const
{
	return	_isSigned;
}

int	Form::getGradeForSign() const
{
	return _gradeForSign;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}
const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

bool Form::beSigned(Bureaucrat &Bu)
{
	if (Bu.getGrade() <= _gradeForSign)
	{
		_isSigned = 1;
		return _isSigned;
	}
	try{
		throw GradeTooLowException();
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form & Fo)
{
	os << "name : " << Fo.getName() << std::endl << "grade :" << Fo.getGrade() << std::endl  << "gradeForSign : " << Fo.getGradeForSign() << std::endl << "isSigned : " << Fo.getIsSigned() << std::endl;
	return os;
}