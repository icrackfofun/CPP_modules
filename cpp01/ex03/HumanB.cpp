/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:39:04 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 17:35:22 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}

HumanB::~HumanB() {}

void		HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (!weapon)
		std::cout << name << " attacks with their" << "... Crap...\n";
	else
	{
		std::string type = weapon->getType();
		std::cout << name << " attacks with their " << type << "\n";
	}
}