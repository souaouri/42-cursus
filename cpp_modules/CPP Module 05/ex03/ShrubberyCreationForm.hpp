#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const & executor) const ;
};