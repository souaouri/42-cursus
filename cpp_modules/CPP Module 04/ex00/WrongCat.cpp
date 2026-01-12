#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat &obj)
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(WrongCat &obj)
{
	if (this != &obj) {
		std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!..." << std::endl;
}