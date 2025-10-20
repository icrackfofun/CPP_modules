/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:27:07 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 17:23:51 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon)
: weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::string type = weapon.getType();

	std::cout << name << " attacks with their " << type << "\n";
}