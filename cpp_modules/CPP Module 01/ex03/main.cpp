/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:48:06 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 12:02:16 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

int main()
{
	{
	  Weapon club = Weapon("crude spiked club");
	  HumanA bob("Bob", club);
	  bob.attack();
	  club.setType("some other type of club");
	  bob.attack();
	}
	{
	  HumanB jim("Jim");
	  Weapon club = Weapon("crude spiked club");
	  jim.setWeapon(club);
	  jim.attack();
	  club.setType("some other type of club");
	  jim.attack();
	}
	return 0;
}