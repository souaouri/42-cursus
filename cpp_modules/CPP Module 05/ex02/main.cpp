#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat tom("Tom", 140);
        Bureaucrat jim("Jim", 50);

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("home");

        std::cout << "\n--- ShrubberyCreationForm Test ---" << std::endl;
        tom.signForm(shrubbery); // Should succeed (grade 140 < 145)
        tom.executeForm(shrubbery); // Should fail (grade 140 > 137)
        bob.executeForm(shrubbery); // Should succeed (grade 1 < 137)

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("Bender");

        std::cout << "\n--- RobotomyRequestForm Test ---" << std::endl;
        jim.signForm(robotomy); // Should succeed (grade 50 < 72)
        jim.executeForm(robotomy); // Should fail (grade 50 > 45)
        bob.executeForm(robotomy); // Should succeed (grade 1 < 45)

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Alice");

        std::cout << "\n--- PresidentialPardonForm Test ---" << std::endl;
        jim.signForm(pardon); // Should fail (grade 50 > 25)
        bob.signForm(pardon); // Should succeed (grade 1 < 25)
        jim.executeForm(pardon); // Should fail (grade 50 > 5)
        bob.executeForm(pardon); // Should succeed (grade 1 < 5)

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
