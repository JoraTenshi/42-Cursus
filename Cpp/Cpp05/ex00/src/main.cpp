/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/08 10:57:49 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	Bureaucrat elon("Elon", 1);
	Bureaucrat musk("Musk", 150);
	std::cout << elon << std::endl;
	std::cout << musk << std::endl;

	elon.decrementGrade();
	musk.incrementGrade();
	std::cout << elon << std::endl;
	std::cout << musk << std::endl;

	try
	{
		Bureaucrat perico("Perico", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat palotes("Palotes", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
