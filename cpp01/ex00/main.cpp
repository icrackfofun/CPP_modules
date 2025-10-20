/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:42:12 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 15:14:12 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int main (void)
{
	Zombie *ricardo;
	ricardo = newZombie("Ricardo");
	ricardo->announce();
	delete(ricardo);

	randomChump("John");
	return (0);
}