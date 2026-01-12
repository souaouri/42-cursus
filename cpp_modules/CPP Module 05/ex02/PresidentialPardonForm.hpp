#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string _target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm & obj);
		PresidentialPardonForm & operator=(PresidentialPardonForm & obj);
		~PresidentialPardonForm();
		
		virtual void	execute(Bureaucrat const & executor)  const ;
};