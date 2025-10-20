/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:37:02 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 17:43:43 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
	name = "";
}

Zombie::~Zombie() 
{
	std::cout << name << "\n";
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

const std::string	&Zombie::getType(void) const
{
	return (name);
}

void Zombie::setName(std::string name)
{
	this->name = name;
}