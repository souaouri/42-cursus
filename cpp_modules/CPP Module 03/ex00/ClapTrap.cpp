/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:09:23 by souaouri          #+#    #+#             */
/*   Updated: 2025/02/07 19:09:23 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string new_name)
{
    std::cout << "ClapTrap Constructor Called" << std::endl;
    this->name = new_name;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
    *this = obj;
}

ClapTrap &ClapTrap::operator=(ClapTrap &obj) {
		 if (this != &obj) { 
        this->name = obj.getName();
        this->Hit_points = obj.getHitPoints();
        this->Energy_points = obj.getEnergyPoints();
        this->Attack_damage = obj.getAttackDamage();
    }
	return *this;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

std::string	ClapTrap::getName()
{
	return this->name;
}
int	ClapTrap::getHitPoints()
{
	return this->Hit_points;
}
int	ClapTrap::getEnergyPoints()
{
	return this->Energy_points;
}
int	ClapTrap::getAttackDamage()
{
	return this->Attack_damage;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->Hit_points = hitPoints;
}
void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->Energy_points = energyPoints;
}
void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->Attack_damage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->Energy_points <= 0 || this->Hit_points <= 0)
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " point of damage" << std::endl;
    this->Energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Energy_points <= 0 || this->Hit_points <= 0)
        return ;
    std::cout << "ClapTrap " << this->name << " lose " << amount << " hp !" << std::endl;
    Energy_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points <= 0 || this->Hit_points <= 0)
        return ;
     std::cout << "ClapTrap " << this->name << " repair itself and gain " << amount << " hp !" << std::endl;
     this->Hit_points += amount;
     this->Energy_points -= 1;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called" << std::endl;
}
