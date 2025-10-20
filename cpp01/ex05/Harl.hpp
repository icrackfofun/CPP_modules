/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:17:51 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/12 20:10:33 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
    	void		(Harl::*funcs[4])();
	public:
		Harl();
		~Harl();
		void    complain(std::string level);
};

#endif