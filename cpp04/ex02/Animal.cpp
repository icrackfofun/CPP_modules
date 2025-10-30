/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:12:56 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/30 00:14:36 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructed!\n";
	type = "Animal";
}

Animal::Animal(const Animal &old)
{
	std::cout << "Animal Copy Constructor Called\n";
	*this = old;
}
Animal	&Animal::operator=(const Animal &old)
{
	std::cout << "Animal Copy Assignment Operator Called\n";
	if (this != &old)
		this->type = old.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destroyed!\n";
}

std::string Animal::getType() const
{
	return (type);
}
