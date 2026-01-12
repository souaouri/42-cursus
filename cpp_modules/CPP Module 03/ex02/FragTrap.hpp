/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:10:56 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:56 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap(std::string name);
		FragTrap();
        FragTrap(FragTrap &src);
        FragTrap& operator=(FragTrap &obj);
        ~FragTrap();
        void    highFivesGuys();
        void    attack(const std::string& target);
    private:
};