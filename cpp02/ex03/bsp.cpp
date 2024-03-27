/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:09:13 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/23 16:21:41 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ccw(Point const a, Point const b, Point const c)
{
	Fixed	temp;

	temp = a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY();
	temp = temp - (b.getX() * a.getY() + c.getX() * b.getY() + a.getX() * c.getY());
	return temp;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	temp1;
	Fixed	temp2;
	Fixed	temp3;

	temp1 = ccw(a, b, point);
	temp2 = ccw(b, c, point);
	temp3 = ccw(c, a, point);
	if ((temp1.toFloat() > 0 && temp2.toFloat() > 0 && temp3.toFloat() > 0)
		|| (temp1.toFloat() < 0 && temp2.toFloat() < 0 && temp3.toFloat() < 0))
		return true;
	return false;
}
