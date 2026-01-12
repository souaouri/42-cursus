/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:47:13 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 11:11:13 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(Dog &obj)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(Dog &obj)
{
	if (this != &obj) {
		std::cout << "Dog Copy Assignment Operator Called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Arf! Arf!" << std::endl;
}