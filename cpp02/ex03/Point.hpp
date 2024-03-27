/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:04:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/22 19:31:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT__
#define __POINT__

#include "Fixed.hpp"

class Point
{

private:
	const Fixed		x;
	const Fixed		y;

public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point &point );
	~Point( void );
	Point &operator=( const Point &point );
	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
