#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade(150), _gradeForSign(150)
{
}

AForm::AForm(std::string name, int grade, int gradeForSign) : _name(name), _grade(grade), _isSigned(0), _gradeForSign(gradeForSign)
{
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm & obj) :  _name("default"), _grade(150), _gradeForSign(150)
{
	*this = obj;
}
AForm & AForm::operator=(AForm & obj)
{
	if (this != &obj)
		this->_isSigned = obj._isSigned;
	return *this;
}


AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return _name;
}

int	AForm::getGrade() const
{
	return _grade;
}

bool	AForm::getIsSigned() const
{
	return	_isSigned;
}

int	AForm::getGradeForSign() const
{
	return _gradeForSign;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}
const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
const char*	AForm::FormNotExecutedException::what() const throw()
{
	return "Form not executed !";
}

bool AForm::beSigned(Bureaucrat &Bu)
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

std::ostream& operator<<(std::ostream& os, const AForm & Fo)
{
	os << "name : " << Fo.getName() << std::endl << "grade :" << Fo.getGrade() << std::endl  << "gradeForSign : " << Fo.getGradeForSign() << std::endl << "isSigned : " << Fo.getIsSigned() << std::endl;
	return os;
}