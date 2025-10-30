/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:57:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/30 00:04:20 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructed!\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &old)
{
	std::cout << "Cat Copy Constructor Called\n";
	this->brain = new Brain(*old.brain);
	this->type = old.type;
}
Cat	&Cat::operator=(const Cat &old)
{
	std::cout << "Cat Copy Assignment Operator Called\n";
	if (this != &old)
	{
		this->type = old.type;
		//if brain, delete
		delete brain;
		this->brain = new Brain(*old.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!\n";
	delete brain;
}

Brain	*Cat::getBrain()
{
	return brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}
