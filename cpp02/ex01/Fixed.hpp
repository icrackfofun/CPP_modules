/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:50:45 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/14 13:59:22 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	fraction;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt( void ) const;
		float	toFloat(void) const;
		friend std::ostream &operator<<(std::ostream &out, const Fixed &f);
};

#endif