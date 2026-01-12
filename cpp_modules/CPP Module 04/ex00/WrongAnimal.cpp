/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:23 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 11:12:03 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Snake";
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &obj)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &obj)
{
	if (this != &obj) {
		std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void	WrongAnimal::setType(std::string new_type)
{
	type = new_type;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Hssssssssssssssss..." << std::endl;
}
