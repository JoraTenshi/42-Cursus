/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:24 by jcallejo          #+#    #+#             */
/*   Updated: 2025/06/06 10:32:36 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static bool inputCheck(std::string str)
{
	if (str.find_first_not_of(" 0123456789") != std::string::npos || str.empty())
		return false;
	return true;
}

static long int get_time()
{
	struct timeval	tv;
	long int		useconds;
	
	gettimeofday(&tv, NULL);
	useconds = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (useconds);
}

int main(int argc, char *argv[])
{
	if (argc <= 2)
	{
		std::cout << RED << "Usage: ./PmergeMe [int1 int2 int3 ...]" << DEFAULT << std::endl;
		return (1);
	}
	
	for (int i = 1; i < argc; i++)
	{
		if (!inputCheck(argv[i]))
		{
			std::cout << RED << "Error: Invalid input. Please enter only positive integers." << DEFAULT << std::endl;
			return (1);
		}
	}

	PmergeMe			merge(&argv[1]);
	std::vector<int>	v = merge.getVector();
	std::list<int>		l = merge.getList();

	long int			start_time;
	long int			vector_time;
	long int			list_time;

	start_time = get_time();
	v = merge.sortVector(v);
	vector_time = get_time() - start_time;

	start_time = get_time();
	l = merge.sortList(l);
	list_time = get_time() - start_time;

	std::cout << ORANGE << "std::vector values before sorting: " << merge.getVector() << DEFAULT << std::endl;
	std::cout << CYAN << "std::vector values after sorting: " << v << DEFAULT << std::endl;
	std::cout << ORANGE << "std::list values before sorting: " << merge.getList() << DEFAULT << std::endl;
	std::cout << CYAN << "std::list values after sorting: " << l << DEFAULT << std::endl;
	std::cout << GREEN << "std::vector: " << vector_time << " microseconds" << DEFAULT << std::endl;
	std::cout << GREEN << "std::list: " << list_time << " microseconds" << DEFAULT << std::endl;
	return (0);
}