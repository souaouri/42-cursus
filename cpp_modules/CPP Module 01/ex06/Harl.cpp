/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:50:37 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/11 09:21:11 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4)
	{
		if (level == levels[i])
		{
			switch (i) {
				case 0:
					while (i < 4)
					{
						std::cout << "---------------------" << levels[i] << "---------------------" << std::endl;
						(this->*func[i])();
						i++;
					}
					break ;
				case 1:
					while (i < 4)
					{
						std::cout << "---------------------" << levels[i] << "---------------------" << std::endl;
						(this->*func[i])();
						i++;
					}
					break ;
				case 2:
					while (i < 4)
					{
						std::cout << "---------------------" << levels[i] << "---------------------" << std::endl;
						(this->*func[i])();
						i++;
					}
					break ;
				case 3:
					while (i < 4)
					{
						std::cout << "---------------------" << levels[i] << "---------------------" << std::endl;
						(this->*func[i])();
						i++;
					}
					break ;
			}
			return ;
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}