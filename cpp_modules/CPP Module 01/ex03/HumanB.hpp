/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:38:39 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:52:40 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon*		Wpn;
	public:
		void	attack();
		void	setWeapon(Weapon &w);
		HumanB(std::string);
};