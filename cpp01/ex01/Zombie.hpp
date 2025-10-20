/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:35:36 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 16:24:14 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();

		void 				announce(void);
		const std::string	&getType(void) const;
		void				setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif