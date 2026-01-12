/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:43 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 09:39:46 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	i = 0;

	if (N < 0)
		return (NULL);
	Zombie *obj = new Zombie[N];

	while(i < N){
		obj[i].setName(name);
		i++;
	}
	return (obj);
}