/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:49:33 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/29 00:14:20 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructed!\n";
	type = "Dog";
}

Dog::Dog(const Dog &old)
{
	std::cout << "Dog Copy Constructor Called\n";
	this->type = old.type;
}

Dog	&Dog::operator=(const Dog &old)
{
	std::cout << "Dog Copy Assignment Operator Called\n";
	if (this != &old)
		this->type = old.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!\n";
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
