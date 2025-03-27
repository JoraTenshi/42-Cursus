/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:43:27 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/27 10:56:58 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaBase = ((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((b.getY() - a.getY()) * (c.getX() - a.getX()));
	Fixed areaABP = ((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX()));
	Fixed areaACP = ((a.getX() - point.getX()) * (c.getY() - point.getY())) - ((a.getY() - point.getY()) * (c.getX() - point.getX()));
	Fixed areaBCP = ((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX()));

	std::cout << "Area base: " << areaBase << std::endl;
	std::cout << "Area ABP: " << areaABP << std::endl;
	std::cout << "Area ACP: " << areaACP << std::endl;
	std::cout << "Area BCP: " << areaBCP << std::endl;

	return (areaBase == (areaABP + areaACP + areaBCP));
}