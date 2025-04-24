/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:59:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 13:43:33 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
	Span base = Span(5);
	std::cout << "Span of five numbers" << std::endl;
	base.addNumber(6);
	base.addNumber(3);
	base.addNumber(17);
	base.addNumber(9);
	base.addNumber(11);

	std::cout << PURPLE << "Span: " << base << DEFAULT << std::endl;
	std::cout << LIGHT_BLUE << "Shortest span: " << base.shortestSpan() << DEFAULT << std::endl;
	std::cout << GREEN << "Longest span: " << base.longestSpan() << DEFAULT << std::endl;
	std::cout << std::endl;
	
	Span longer = Span(10000);
	std::cout << "Span of 10000 numbers" << std::endl;
	longer.fillRange();
	std::cout << LIGHT_BLUE << "Shortest span: " << longer.shortestSpan() << DEFAULT << std::endl;
	std::cout << GREEN << "Longest span: " << longer.longestSpan() << DEFAULT << std::endl;
	std::cout << std::endl;

	Span error = Span(1);
	std::cout << "Span of one number" << std::endl;
	error.addNumber(1);
	error.addNumber(2);
	std::cout << LIGHT_BLUE << "Shortest span: " << error.shortestSpan() << DEFAULT << std::endl;
	std::cout << GREEN << "Longest span: " << error.longestSpan() << DEFAULT << std::endl;
	std::cout << std::endl;
	
	return 0;
}

