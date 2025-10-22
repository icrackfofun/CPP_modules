/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:56:50 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/22 23:57:30 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &old);
		Cat	&operator=(const Cat &old);
		~Cat();

		void	makeSound() const;
};

#endif