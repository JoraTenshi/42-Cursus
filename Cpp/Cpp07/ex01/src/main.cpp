/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:17 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/23 11:41:29 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

static void printChar(char &c)
{
	std::cout << c << std::endl;
}

static void printN(int &n)
{
	std::cout << n << std::endl;
}

static void printStr(std::string &str)
{
	std::cout << str << std::endl;
}

int main( void ) 
{
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "!"};

	std::cout << "Testing char:" << std::endl;
	iter(charArray, sizeof(charArray) / sizeof(char), printChar);
	std::cout << std::endl;

	std::cout << "Testing int:" << std::endl;
	iter(intArray, sizeof(intArray) / sizeof(int), printN);
	std::cout << std::endl;

	std::cout << "Testing string:" << std::endl;
	iter(strArray, sizeof(strArray) / sizeof(std::string), printStr);
	std::cout << std::endl;

	return 0;
}