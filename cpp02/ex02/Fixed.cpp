/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:04:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/27 17:31:33 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->fract_bits;
}

Fixed::Fixed(const float value)
{
	this->value = std::roundf(value * (1 << this->fract_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed(void) {}

Fixed & Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
	{
		this->value = fixed.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int		Fixed::toInt(void) const
{
	return this->value >> this->fract_bits;
}

float	Fixed::toFloat(void) const
{
	return (float)this->value / (1 << fract_bits);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->value == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->value != fixed.getRawBits();
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->value > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->value < fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->value <= fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->value >= fixed.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	this->value++;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	this->value--;
	return (*this);
}

const Fixed		Fixed::operator++( int )
{
	Fixed	t(*this);

	this->value++;
	return t;
}

const Fixed		Fixed::operator--( int )
{
	Fixed	t(*this);

	this->value--;
	return t;
}

Fixed	&Fixed::max( Fixed &fixed1, Fixed &fixed2 )
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}

Fixed	&Fixed::min( Fixed &fixed1, Fixed &fixed2 )
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}

const Fixed	&Fixed::max( const Fixed &fixed1, const Fixed &fixed2 )
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}
const Fixed	&Fixed::min( const Fixed &fixed1, const Fixed &fixed2 )
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
