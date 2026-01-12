#include "Intern.hpp"

Intern::Intern(){

}

Intern::Intern(Intern & obj)
{
	*this = obj;
}

Intern & Intern::operator=(Intern & obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern(){

}

AForm* createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int position;

	for (int i = 0; i < 3; i++)
	{
		if (formName == arr[i])
		{
			position = i;
			break;
		}
		position = -1337;
	}

	AForm* (*func[3])(std::string) =  {&createShrubbery, &createRobotomy, &createPresidential};

	try{
		std::string exeption = "Intern failed to creates form!";
		if (position == -1337)
			throw exeption;
		std::cout << "Intern creates " << formName << std::endl;
		return (func[position](target));
	}
	catch(std::string &e)
	{
		std::cout << e << std::endl;
		return (NULL);
	}
}