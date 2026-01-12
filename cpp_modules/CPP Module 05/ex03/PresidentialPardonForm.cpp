#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _target(target){

}

PresidentialPardonForm::~PresidentialPardonForm(){

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > getGrade())
		throw FormNotExecutedException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}