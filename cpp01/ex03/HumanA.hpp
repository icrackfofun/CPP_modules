/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:02 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 17:23:47 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void		attack();
};

#endif