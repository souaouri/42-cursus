/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:10:21 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:21 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int	main() {
	ClapTrap	leo("Messi");
	ClapTrap	*Romeo = new ScavTrap("Roméo");
	ScavTrap	Cristiano("Cris");

	leo.attack("Cris");
	Cristiano.takeDamage(leo.getAttackDamage());
	Cristiano.beRepaired(18);
	Cristiano.guardGate();
	delete Romeo;
	return 0;
}