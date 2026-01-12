/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:56:43 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 11:09:04 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(Brain &obj)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(Brain &obj)
{
	if (this != &obj) {
		for (int i = 0; i <= 100; i++)
			this->ideas[i] = obj.ideas[i];
		std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}
