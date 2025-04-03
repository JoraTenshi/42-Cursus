/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:21:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 14:56:31 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

int main(void) {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point pointInside(2, 2);
	Point pointOutside(10, 10);

	if (bsp(a, b, c, pointInside))
	std::cout << "Point is outside the triangle" << std::endl;
	else
	std::cout << "Point is inside the triangle" << std::endl;

	if (bsp(a, b, c, pointOutside))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return (0);
}