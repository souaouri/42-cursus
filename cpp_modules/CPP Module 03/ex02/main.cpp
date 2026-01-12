/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:11:01 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:11:01 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	leo("Messi");
	ClapTrap	*Rodry = new ScavTrap("KDB");
	FragTrap	Cris("Cristiano");

	leo.attack("Cristiano");
	Cris.takeDamage(Cris.getAttackDamage());
	Cris.beRepaired(18);
	Cris.highFivesGuys();
	Cris.attack("KDB");
	Rodry->takeDamage(Cris.getAttackDamage());
	delete Rodry;
	return 0;
}