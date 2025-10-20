/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:52:52 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/15 16:27:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed()
{
	fixed = 0;
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int i)
{
	fixed = i << fraction;
	//std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float f)
{
	fixed = roundf(f * (1 << fraction));
	//std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &old)
{
	this->fixed = old.fixed;
	//std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &old)
{
	if (this != &old)
		this->fixed = old.fixed;
	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called\n";
    return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called\n";
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

bool Fixed::operator>(const Fixed &other) const
{
	return this->fixed > other.fixed;
}
bool Fixed::operator<(const Fixed &other) const
{
	return this->fixed < other.fixed;
}
bool Fixed::operator>=(const Fixed &other) const
{
	return this->fixed >= other.fixed;
}
bool Fixed::operator<=(const Fixed &other) const
{
	return this->fixed <= other.fixed;
}
bool Fixed::operator==(const Fixed &other) const
{
	return this->fixed == other.fixed;
}
bool Fixed::operator!=(const Fixed &other) const
{
	return this->fixed != other.fixed;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
    result.setRawBits(this->fixed + other.fixed);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
    result.setRawBits(this->fixed - other.fixed);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
    long temp = (long)this->fixed * (long)other.fixed;
    result.setRawBits((int)(temp >> fraction));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
    long temp = ((long)this->fixed << fraction) / other.fixed;
    result.setRawBits((int)temp);
    return result;
}

Fixed &Fixed::operator++()
{
	++fixed;
    return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
    ++fixed;
    return temp;
}

Fixed &Fixed::operator--()
{
	--fixed;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
    --fixed;
    return temp;
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed  &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed  &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
