/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:00:08 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/30 00:20:09 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}
