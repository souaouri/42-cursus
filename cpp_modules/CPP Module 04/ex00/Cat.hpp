/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:42:52 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/12 18:16:43 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(Cat &obj);
		Cat& operator=(Cat &obj);
		~Cat();
		void	makeSound() const;
};