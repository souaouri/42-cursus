/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:19:28 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/09 12:50:38 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "please enter three parameters" << std::endl;
		exit (1);
	}
	_replace(argv[1], argv[2], argv[3]);
}