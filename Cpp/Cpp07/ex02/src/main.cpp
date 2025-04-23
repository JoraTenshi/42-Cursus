/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:43:44 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/23 12:03:28 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

static void printArray(Array<int> &arr)
{
	std::cout << "{ ";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << (i != arr.size() - 1 ? ", " : "");
	std::cout << " }" << std::endl;
}

int main()
{
	Array<int> intArray(5);

	std::cout << "INT ARRAY" << std::endl;
	for (int i = 0; i < intArray.size(); i++)
		intArray[i] = i;

	printArray(intArray);

	std::cout << "INT ARRAY COPY" << std::endl;
	Array<int> intArrayCopy(intArray);
	printArray(intArrayCopy);

	std::cout << "INT ARRAY EXCEPTION TEST" << std::endl;
	try
	{
		intArray[42];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}