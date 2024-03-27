/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:04:52 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/23 15:54:30 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &point): x(point.getX()), y(point.getY()) {}

Point::~Point(void) {}

Point	&Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->~Point();
		new(this) Point(point.getX().toFloat(), point.getY().toFloat());
	}
	return *this;
}

Fixed	Point::getX(void) const
{
	return this->x;
}

Fixed	Point::getY(void) const
{
	return this->y;
}
