/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:09:30 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:09:30 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	leo("Messi");
	ClapTrap	cris("Cristiano");

	leo.attack("Cris");
	cris.takeDamage(leo.getAttackDamage());
	cris.beRepaired(2);

	return 0;
}