/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:42:12 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 15:38:56 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int main (void)
{
	Zombie *horde;
	int N = 5;

	horde = zombieHorde(N, "John");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}