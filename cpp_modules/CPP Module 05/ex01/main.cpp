#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

using namespace std;


int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        Form f1("Tax Form", 100, 50); // name, gradeToSign, gradeToExecute

        std::cout << f1 << std::endl; // Print initial form status

        b1.signForm(f1); // Attempt signing

		std::cout << std::endl;

        std::cout << f1 << std::endl; // Check form status after signing
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl; 
    }

    // Test with too low grade
    try
    {
        Bureaucrat b2("Bob", 150);  // ######  GradeTooLowException ######
        Form f2("Secret Form", 50, 50);

        std::cout << f2 << std::endl;

        b2.signForm(f2); // Should fail due to low grade

		std::cout << std::endl;

        std::cout << f2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
