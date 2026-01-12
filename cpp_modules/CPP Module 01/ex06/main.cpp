/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:46:16 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:58:41 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "please enter one parameter !" << std::endl;
		exit (1);
	}
	Harl obj;

	obj.complain(argv[1]);
	return (0);
}