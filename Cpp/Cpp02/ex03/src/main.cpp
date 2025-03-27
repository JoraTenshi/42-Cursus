/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:21:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/27 10:42:18 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "bsp.cpp"

int main(void) {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point pointInside(2, 2);
	Point pointOutside(10, 10);

	if (!bsp(a, b, c, pointInside))
		std::cout << "Point " << pointInside << " is not inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;
	else
		std::cout << "Point " << pointInside << " is inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;

	if (!bsp(a, b, c, pointOutside))
		std::cout << "Point " << pointOutside << " is not inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;
	else
		std::cout << "Point " << pointOutside << " is inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;

	return (0);
}