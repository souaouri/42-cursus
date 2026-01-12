/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:40:17 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 10:22:37 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal &obj);
		Animal& operator=(Animal &obj);
		virtual ~Animal();
		void		setType(std::string new_type);
		std::string	getType() const;
		virtual void		makeSound() const;
};
