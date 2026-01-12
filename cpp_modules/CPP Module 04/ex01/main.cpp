/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:04 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/14 12:04:10 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *a = new Animal;
	std::cout << "----- Animal sound -----" << std::endl;
	a->makeSound();
	std::cout << "-------------------------" << std::endl;
	delete a;
	int size = 6;
	Animal *pet[size];
	int i = 0;
	while (i < size)
	{
		if (i < size / 2)
		{
			std::cout << "__________ Dog __________" <<std::endl;
			pet[i] = new Dog();
		}
		else
		{
			std::cout << "___________ Cat ________" <<std::endl;
		 	pet[i] = new Cat();
		}
		i++;
	}
	for (i = 0; i < 6; i++) {
		pet[i]->makeSound();
	}
	for (i = 0; i < size; i++)
	{
		std::cout << "_____________ delete __________\n";
		delete pet[i];
	}
}