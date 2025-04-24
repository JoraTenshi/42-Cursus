/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:29:25 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 11:37:03 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Easyfind.hpp"

int main()
{
	std::vector<int> 	vec;

	std::cout << "Vector:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	try
	{
		easyfind(vec, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		easyfind(vec, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}