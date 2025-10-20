/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:30:08 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/14 12:51:29 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					fixed;
		static const int	fraction;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif