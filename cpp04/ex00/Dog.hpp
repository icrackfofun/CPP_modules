/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:46:07 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/22 23:55:53 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &old);
		Dog	&operator=(const Dog &old);
		~Dog();

		void	makeSound() const;
};

#endif