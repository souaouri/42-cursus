/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:14 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:59:40 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon& wn): Wpn(wn)
{
	this->name = nm;
	Wpn.setType(wn.getType());
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << Wpn.getType() << std::endl;
}