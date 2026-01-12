/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:42:52 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/12 22:55:07 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* brain_cat;
	public:
		Cat();
		Cat(Cat &obj);
		Cat& operator=(Cat &obj);
		~Cat();
		void	makeSound() const;
};