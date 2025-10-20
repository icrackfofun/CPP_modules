/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 23:48:26 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/20 00:09:08 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructed!\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &old)
: ClapTrap(old)
{
	std::cout << "FragTrap Copy constructor called\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &old)
{
	if (this != &old)
	{
		this->name = old.name;
		this->energyPoints = old.energyPoints;
		this->hitPoints = old.hitPoints;
		this->attackDamage = old.attackDamage;
	}
	std::cout << "FragTrap Copy assignment operator called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name <<" can't Attack, no Energy Points Left!\n";
		return ;
	}
	--energyPoints;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " Wants some High-Five Action!" << "\n";
}