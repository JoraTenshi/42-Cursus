/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:38:34 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/27 10:41:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point()
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY())
{
	std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "Float constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &point)
	{
		(Fixed)_x = point.getX();
		(Fixed)_y = point.getY();
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

std::ostream &operator<<(std::ostream &out, Point const &point)
{
	out << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (out);
}