/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:14:24 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/29 00:16:04 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "Wrong Cat constructed!\n";
	type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &old)
{
	std::cout << "Wrong Cat Copy Constructor Called\n";
	this->type = old.type;
}
WrongCat	&WrongCat::operator=(const WrongCat &old)
{
	std::cout << "Wrong Cat Copy Assignment Operator Called\n";
	if (this != &old)
		this->type = old.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destroyed!\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!\n";
}
