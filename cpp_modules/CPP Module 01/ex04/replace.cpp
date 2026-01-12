/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:49:58 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 11:55:43 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	_replace(std::string file_name, std::string str1, std::string str2)
{
	std::ifstream inputfile(file_name);
	if (!inputfile.is_open()){
		std::cout << "Failed to open the file." << std::endl;
			exit (1);
	}
	std::string line;
	std::string name_replace;

	name_replace = file_name + ".replace";

	std::ofstream outputfile(name_replace);
	if(!outputfile.is_open()){
		std::cout << "Failed to open the file." << std::endl;
			exit (1);
	}
	size_t begin = 0;

	getline(inputfile, line, '\0');
	while ((begin = line.find(str1, begin)) != std::string::npos && !str1.empty())
	{
		line.erase(begin , str1.size());
		line.insert(begin, str2);
		begin += str2.size();
	}
	outputfile << line;
	outputfile.close();
	inputfile.close();
}