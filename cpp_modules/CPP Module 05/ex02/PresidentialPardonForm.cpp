#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _target(target){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & obj)
{
	*this = obj;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & obj)
{
	if (this != &obj)
		this->_target = obj._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > getGrade())
		throw FormNotExecutedException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}