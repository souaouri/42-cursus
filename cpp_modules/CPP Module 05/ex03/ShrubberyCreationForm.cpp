#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), _target(target){
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	if (executor.getGrade() > getGrade())
		throw FormNotExecutedException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		throw "error in open file !";
	for (int i = 7; i >= 0; i--)
	{
		file << "         ##      " << std::endl;
		file << "        ####       " << std::endl;
		file << "       ######     " << std::endl;
		file << "      ########       " << std::endl;
		file << "     ##########    " << std::endl;
		file << "    ############       " << std::endl;
		file << "   ##############       " << std::endl;
		file << "  ################       " << std::endl;
		file << "         ||      " << std::endl;
		file << "         ||      " << std::endl;
		file << "         ||      " << std::endl;
		file << "         ||      " << std::endl;
		file << "         ||      " << std::endl;
		file << std::endl;
	}

	
	file.close();
}