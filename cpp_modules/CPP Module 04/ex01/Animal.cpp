/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:14:00 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 11:09:14 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Snake";
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(Animal &obj)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(Animal &obj)
{
	if (this != &obj) {
		std::cout << "Animal Copy Assignment Operator Called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::setType(std::string new_type)
{
	type = new_type;
}

std::string	Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Hssssssssssssssss..." << std::endl;
}
