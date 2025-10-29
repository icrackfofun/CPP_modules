/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:57:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/25 12:31:19 by psantos-         ###   ########.fr       */
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
	*this = old;
}
Cat	&Cat::operator=(const Cat &old)
{
	std::cout << "Cat Copy Assignment Operator Called\n";
	if (this != &old)
	{
		this->type = old.type;
		this->brain = old.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!\n";
	delete[] brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}
