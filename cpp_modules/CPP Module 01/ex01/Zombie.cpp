/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:03:35 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/07 13:24:27 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::Zombie()
{

}

void	Zombie::setName(std::string name)
{
	this-> name = name;
}

Zombie::~Zombie(){
	std::cout << "delete Zombie ---> " << name << std::endl;
}