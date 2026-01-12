/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:35:36 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:49:40 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class	Zombie{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		void 	announce( void );
		~Zombie();
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );