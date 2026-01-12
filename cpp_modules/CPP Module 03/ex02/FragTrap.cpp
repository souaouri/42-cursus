/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:10:53 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:53 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name){
    std::cout << "FragTrap Constructor Called" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
    this->name = name;
}

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap &obj){
    *this = obj;
}

FragTrap& FragTrap::operator=(FragTrap &obj) {
    if (this != &obj) { 
        this->name = obj.getName();
        this->Hit_points = obj.getHitPoints();
        this->Energy_points = obj.getEnergyPoints();
        this->Attack_damage = obj.getAttackDamage();
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor Called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->Energy_points <= 0 || this->Hit_points <= 0)
        return ;
	std::cout << this->name << " : Who wants a high-five ?" << std::endl;
}
void FragTrap::attack(const std::string& target) {
	if (this->Energy_points <= 0 || this->Hit_points <= 0)
        return ;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing damage" << std::endl;
	this->Energy_points -= 1;
}
