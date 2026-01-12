/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:41:25 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/12 22:09:20 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* brain_dog;
	public:
		Dog();
		Dog(Dog &obj);
		Dog& operator=(Dog &obj);
		~Dog();
		void	makeSound() const;
};