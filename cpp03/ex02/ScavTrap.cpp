/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 23:17:59 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/20 00:09:16 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructed!\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old)
: ClapTrap(old)
{
	std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &old)
{
	if (this != &old)
	{
		this->name = old.name;
		this->energyPoints = old.energyPoints;
		this->hitPoints = old.hitPoints;
		this->attackDamage = old.attackDamage;
	}
	std::cout << "ScavTrap Copy assignment operator called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name <<" can't Attack, no Energy Points Left!\n";
		return ;
	}
	--energyPoints;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << "\n";
}