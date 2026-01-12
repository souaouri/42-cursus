#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm & obj);
		RobotomyRequestForm & operator=(RobotomyRequestForm & obj);
		~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const & executor) const ;
};