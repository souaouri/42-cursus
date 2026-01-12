/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:39:47 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 12:00:17 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << Wpn->getType() << std::endl;
}

HumanB::HumanB(std::string nm)
{
	this->name = nm;
}

void	HumanB::setWeapon(Weapon& w)
{
	Wpn = &w;
}