#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	try{
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1); // Highest grade bureaucrat

		// Test 1: Create a RobotomyRequestForm
		AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1; // Always delete allocated forms
		}

		std::cout << "---------------------------------" << std::endl;

		// Test 2: Create a ShrubberyCreationForm
		AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}

		std::cout << "---------------------------------" << std::endl;

		// Test 3: Create a PresidentialPardonForm
		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}

		std::cout << "---------------------------------" << std::endl;

		// Test 4: Try to create a non-existent form
		AForm* form4 = someRandomIntern.makeForm("unknown form", "target");
		if (form4)
			delete form4;
	}
	catch(std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}