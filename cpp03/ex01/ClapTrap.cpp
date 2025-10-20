/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:59:27 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/19 23:59:36 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " constructed!\n";
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &old)
{
	this->name = old.name;
	this->energyPoints = old.energyPoints;
	this->hitPoints = old.hitPoints;
	this->attackDamage = old.attackDamage;
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &old)
{
	if (this != &old)
	{
		this->name = old.name;
		this->energyPoints = old.energyPoints;
		this->hitPoints = old.hitPoints;
		this->attackDamage = old.attackDamage;
	}
	std::cout << "ClapTrap Copy assignment operator called\n";
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called\n";
}

void ClapTrap::setAttackDamage(unsigned int n)
{
	std::cout << "ClapTrap " << name << " Attack Damage set to " << n << "\n";
	attackDamage = n;
}

void ClapTrap::addEnergyPoints(unsigned int n)
{
	std::cout << "ClapTrap " << name << " New Energy Points: " << energyPoints + n << "\n";
	energyPoints += n;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name <<" can't Attack, no Energy Points Left!\n";
		return ;
	}
	--energyPoints;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining HP: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't repair — no energy left!" << "\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;

    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! New HP: " << hitPoints << "\n";
}
