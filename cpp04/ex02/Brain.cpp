/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:35:30 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/29 23:58:43 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed!\n";
}

Brain::Brain(const Brain &old)
{
	std::cout << "Brain Copy Constructor Called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = old.ideas[i];
}

Brain	&Brain::operator=(const Brain &old)
{
	std::cout << "Brain Copy Assignment Operator Called\n";
	if (this != &old)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = old.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed!\n";
}
