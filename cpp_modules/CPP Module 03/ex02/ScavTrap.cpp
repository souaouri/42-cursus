/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:11:05 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:11:05 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name){
    std::cout << "ScavTrap Constructor Called" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
    this->name = name;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj){
    *this = obj;
}

ScavTrap& ScavTrap::operator=(ScavTrap &obj) {
    if (this != &obj) { 
        this->name = obj.getName();
        this->Hit_points = obj.getHitPoints();
        this->Energy_points = obj.getEnergyPoints();
        this->Attack_damage = obj.getAttackDamage();
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->Energy_points == 0 || this->Hit_points == 0)
        return ;
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->Energy_points == 0 || this->Hit_points == 0)
        return ;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing damage" << std::endl;
	this->Energy_points -= 1;
}
