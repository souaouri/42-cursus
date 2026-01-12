#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 45, 72), _target(target){

}

RobotomyRequestForm::~RobotomyRequestForm(){

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	if (executor.getGrade() > getGrade())
		throw FormNotExecutedException();
	srand(time(0));
	int rend = rand();
	if (rend % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
