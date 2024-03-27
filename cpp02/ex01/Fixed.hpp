/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:04:18 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/20 19:20:55 by seonyoon         ###   ########.fr       */
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
	Fixed &operator=( const Fixed &fixed );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
