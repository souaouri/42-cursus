/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:06 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 09:34:30 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	Zombie *obj;

	std::cout << "creat   --> ";
	obj = newZombie("rboutaik");
	obj->announce();
	std::cout << "creat   --> ";
	randomChump("souaouri");

	delete obj;
	return (0);
}