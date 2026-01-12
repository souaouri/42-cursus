/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:43:52 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/15 11:59:30 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain_cat = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(Cat& obj) {
        std::cout << "Cat Copy Constructor Called" << std::endl;
        type = obj.type;
        brain_cat = new Brain();
		brain_cat = obj.brain_cat;
    }

Cat& Cat::operator=(Cat &obj)
{
	if (this != &obj) {
		std::cout << "Cat Copy Assignment Operator Called" << std::endl;
		type = obj.type;
        delete brain_cat;
        brain_cat = new Brain();
		brain_cat = obj.brain_cat;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete brain_cat;
}

void Cat::makeSound() const
{
	std::cout << "Meow!..." << std::endl;
}