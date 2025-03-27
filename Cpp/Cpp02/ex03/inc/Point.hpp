/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:34:05 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/27 10:36:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

		public:
			Point();
			Point(const Point &point);
			Point(const float x, const float y);
			~Point();

			Point &operator=(const Point &point);
			Fixed getX() const;
			Fixed getY() const;
};

std::ostream &operator<<(std::ostream &out, Point const &point);