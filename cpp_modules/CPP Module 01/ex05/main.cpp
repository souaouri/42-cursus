/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:46:16 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:56:34 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
	Harl obj;

	std::cout << "---------------------DEBUG---------------------" << std::endl;
	obj.complain("DEBUG");
	std::cout << "---------------------INFO----------------------" << std::endl;
	obj.complain("INFO");
	std::cout << "---------------------WARNING-------------------" << std::endl;
	obj.complain("WARNING");
	std::cout << "---------------------ERROR---------------------" << std::endl;
	obj.complain("ERROR");

	return (0);
}