/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:37:54 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 17:30:28 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		~HumanB();

		void		setWeapon(Weapon &weapon);
		void		attack();
};

#endif