/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:43:52 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 11:10:54 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(Cat &obj)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(Cat &obj)
{
	if (this != &obj) {
		std::cout << "Cat Copy Assignment Operator Called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!..." << std::endl;
}