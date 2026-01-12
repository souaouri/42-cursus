/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:50:59 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 12:02:06 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanA{
	private:
		std::string name;
		Weapon&		Wpn;
	public:
		void	attack();
		HumanA(std::string, Weapon&);
};