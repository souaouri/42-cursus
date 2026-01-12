/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:21:42 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/12 18:33:19 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &obj);
		WrongAnimal& operator=(WrongAnimal &obj);
		~WrongAnimal();
		void		setType(std::string new_type);
		std::string	getType() const;
		void		makeSound() const;
};
