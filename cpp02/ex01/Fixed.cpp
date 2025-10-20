/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:52:52 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/14 17:41:32 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed()
{
	fixed = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int i)
{
	fixed = i << fraction;
	std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float f)
{
	fixed = roundf(f * (1 << fraction));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &old)
{
	this->fixed = old.fixed;
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &old)
{
	if (this != &old)
		this->fixed = old.fixed;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->fixed = raw;
}

int	Fixed::toInt( void ) const
{
	return (fixed / (1 << fraction));
}

float Fixed::toFloat(void) const
{
	return (float)fixed / (1 << fraction);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
