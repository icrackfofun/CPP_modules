/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:10:13 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/23 00:12:03 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal constructed!\n";
	type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &old)
{
	std::cout << "Wrong Animal Copy Constructor Called\n";
	*this = old;
}
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &old)
{
	std::cout << "Wrong Animal Copy Assignment Operator Called\n";
	if (this != &old)
		this->type = old.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destroyed!\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound!\n";
}

std::string WrongAnimal::getType() const
{
	return (type);
}
