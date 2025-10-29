/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:00:08 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/23 00:27:41 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main ()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << "\n";
	std::cout << j->getType() << " " << "\n";
	std::cout << i->getType() << " " << "\n";
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "\n";
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongc = new WrongCat();
	std::cout << wrong->getType() << " " << "\n";
	std::cout << wrongc->getType() << " " << "\n";
	wrong->makeSound();
	wrongc->makeSound();
	delete wrong;
	delete wrongc;
	return 0;
}
