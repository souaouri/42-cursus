
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class ShrubberyCreationForm;

class Intern{
	public:
		Intern();
		Intern(Intern & obj);
		Intern & operator=(Intern & obj);
		~Intern();
		AForm* makeForm(std::string formName, std::string target);
};

AForm* createShrubbery(std::string target);
AForm* createRobotomy(std::string target);
AForm* createPresidential(std::string target);