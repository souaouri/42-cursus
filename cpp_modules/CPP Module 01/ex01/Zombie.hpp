/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:29 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:50:46 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Zombie{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie();
		void 	announce( void );
		void	setName(std::string name);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );