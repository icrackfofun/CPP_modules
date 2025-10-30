/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:49:33 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/30 00:04:12 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructed!\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &old)
{
	std::cout << "Dog Copy Constructor Called\n";
	this->brain = new Brain(*old.brain);
	this->type = old.type;
}
Dog	&Dog::operator=(const Dog &old)
{
	std::cout << "Dog Copy Assignment Operator Called\n";
	if (this != &old)
	{
		this->type = old.type;
		//if brain, delete
		delete brain;
		this->brain = new Brain(*old.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!\n";
	delete brain;
}

Brain	*Dog::getBrain()
{
	return brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
