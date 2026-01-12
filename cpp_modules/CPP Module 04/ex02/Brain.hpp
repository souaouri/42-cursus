/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:22:40 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/12 22:56:38 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain &obj);
		Brain& operator=(Brain &obj);
		~Brain();
};