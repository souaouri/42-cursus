#include <iostream>
#include "Bureaucrat.hpp"
#include <vector>

using namespace std;


int main()
{
    try
    {
        Bureaucrat bob("Bob", 0); // Invalid grade, should throw GradeTooHighException
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl; // prints: Grade too high!
    }

    try
    {
        Bureaucrat alice("Alice", 151); // Invalid grade, should throw GradeTooLowException
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl; // prints: Grade too low!
    }

    try
    {
        Bureaucrat john("John", 2);
        std::cout << john; // prints: John, bureaucrat grade 2.
        john.incrementGrade(); // makes grade 1
        std::cout << john; // prints: John, bureaucrat grade 1.
        john.incrementGrade(); // grade 0 -> throws GradeTooHighException
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl; // prints: Grade too high!
    }

	try 
	{
		Bureaucrat Cris("Cris", 150);
		std::cout << Cris;     // prints: Cris, bureaucrat grade 150.
		Cris.decrementGrade(); // grade 151 -> throws GradeTooLowException
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl; // prints: Grade too low!
	}

    return 0;
}