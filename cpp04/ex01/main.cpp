/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:00:08 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/30 00:10:34 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int size = 6;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << "\n--- Making sounds ---\n";
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	std::cout << "\n--- Printing brains ---\n";
	for (int i = 0; i < size; i++)
	{
		Dog* dog = dynamic_cast<Dog*>(animals[i]);
		Cat* cat = dynamic_cast<Cat*>(animals[i]);

		if (dog)
			std::cout << "Dog brain pointer: " << dog->getBrain() << "\n";
		else if (cat)
			std::cout << "Cat brain pointer: " << cat->getBrain() << "\n";
		else
			std::cout << "Unknown animal type.\n";
	}
	
	std::cout << "\n--- Comparing brains ---\n";	
	Dog original;
	Dog copy = original;
	std::cout << original.getBrain() << " vs " << copy.getBrain() << "\n";

	std::cout << "\n--- Deleting animals ---\n";
	for (int i = 0; i < size; i++)
		delete animals[i];
	std::cout << "\n";

	return 0;
}
