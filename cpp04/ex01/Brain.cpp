/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:35:30 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/29 00:40:57 by psantos-         ###   ########.fr       */
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
	std::cout << "Animal Copy Constructor Called\n";
}

Brain	&Brain::operator=(const Brain &old)
{
	std::cout << "Animal Copy Assignment Operator Called\n";
}

Brain::~Brain()
{
	std::cout << "Animal destroyed!\n";
}