/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:11:07 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:11:07 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap(std::string name);
        ScavTrap();
        ScavTrap(ScavTrap &src);
        ScavTrap& operator=(ScavTrap &obj);
        ~ScavTrap();
        void    guardGate();
        void    attack(const std::string& target);
    private:
};