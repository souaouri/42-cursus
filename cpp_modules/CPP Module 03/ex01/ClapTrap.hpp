/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:10:18 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:18 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        int         Hit_points;
        int         Energy_points;
        int         Attack_damage;
    public:
        ClapTrap(std::string new_name);
		ClapTrap();
        ClapTrap(ClapTrap &obj);
        ClapTrap& operator=(ClapTrap &obj);
        virtual ~ClapTrap();
        std::string	    getName();
        int	    getHitPoints();
        int	    getEnergyPoints();
        int     getAttackDamage();
        void    setHitPoints(int hitPoints);
        void	setEnergyPoints(int energyPoints);
        void	setAttackDamage(int attackDamage);
        virtual void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};