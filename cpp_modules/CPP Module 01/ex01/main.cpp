/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:11:20 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:50:34 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	Zombie *obj;
	int		i = 0;
	int 	N = 8;
	
	obj = zombieHorde(N, "Zombie");
	while (i < N)
	{
		obj[i].announce();
		i++;
	}
	delete[] obj;
	return (0);
}