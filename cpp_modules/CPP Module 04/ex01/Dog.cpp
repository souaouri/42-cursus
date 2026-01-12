/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:47:13 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/15 11:59:46 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	type = "Dog";
	brain_dog = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(Dog &obj)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	type = obj.type;
    brain_dog = new Brain();
	brain_dog = obj.brain_dog;
}

Dog& Dog::operator=(Dog &obj)
{
	if (this != &obj) {
		std::cout << "Dog Copy Assignment Operator Called" << std::endl;
		type = obj.type;
        delete brain_dog;
        brain_dog = new Brain();
		brain_dog = obj.brain_dog;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete brain_dog;
}

void Dog::makeSound() const
{
	std::cout << "Arf! Arf!" << std::endl;
}