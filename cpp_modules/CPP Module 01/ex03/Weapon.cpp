/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:47 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 10:17:16 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}

Weapon::Weapon(std::string type)
{
	setType(type);
}
