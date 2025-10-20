/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:58:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 16:16:52 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string	&getType() const;
		void				setType(std::string type);			
};

#endif