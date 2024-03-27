/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:04:18 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/20 19:20:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
#define __FIXED__

#include <iostream>

class Fixed
{

private:
	int					value;
	static const int	fract_bits = 8;

public:
	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed &fixed );
	~Fixed( void );
	Fixed & operator = ( const Fixed &fixed );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;
	bool	operator==( const Fixed &fixed ) const;
	bool	operator!=( const Fixed &fixed ) const;
	bool	operator<( const Fixed &fixed ) const;
	bool	operator>( const Fixed &fixed ) const;
	bool	operator<=( const Fixed &fixed ) const;
	bool	operator>=( const Fixed &fixed ) const;
	Fixed	operator+( const Fixed &fixed ) const;
	Fixed	operator-( const Fixed &fixed ) const;
	Fixed	operator*( const Fixed &fixed ) const;
	Fixed	operator/( const Fixed &fixed ) const;
	Fixed				&operator++( void );
	Fixed				&operator--( void );
	const Fixed			operator++( int );
	const Fixed			operator--( int );
	static Fixed		&max( Fixed &fixed1, Fixed &fixed2 );
	static Fixed		&min( Fixed &fixed1, Fixed &fixed2 );
	static const Fixed	&max( const Fixed &fixed1, const Fixed &fixed2 );
	static const Fixed	&min( const Fixed &fixed1, const Fixed &fixed2 );

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
