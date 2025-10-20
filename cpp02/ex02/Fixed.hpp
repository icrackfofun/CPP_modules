/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:50:45 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/15 16:23:03 by psantos-         ###   ########.fr       */
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
		
		bool operator>(const Fixed &other) const;
    	bool operator<(const Fixed &other) const;
    	bool operator>=(const Fixed &other) const;
    	bool operator<=(const Fixed &other) const;
    	bool operator==(const Fixed &other) const;
    	bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
    	Fixed operator-(const Fixed &other) const;
    	Fixed operator*(const Fixed &other) const;
    	Fixed operator/(const Fixed &other) const;
		
		Fixed &operator++();
    	Fixed operator++(int);
    	Fixed &operator--();
    	Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
    	static const Fixed &min(const Fixed &a, const Fixed &b);
    	static Fixed &max(Fixed &a, Fixed &b);
    	static const Fixed &max(const Fixed &a, const Fixed &b);

		friend std::ostream &operator<<(std::ostream &out, const Fixed &f);
};

#endif