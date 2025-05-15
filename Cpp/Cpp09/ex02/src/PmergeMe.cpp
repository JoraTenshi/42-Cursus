/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:32 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/14 12:25:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		_vec.push_back(num);
		_list.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_list = src._list;
	}
	return *this;
}

static int isVecSorted(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1])
			return 0;
	}
	return 1;
}

static int isListSorted(std::list<int> &lst)
{
	std::list<int>::iterator it = lst.begin();
	int prev = *it;
	++it;
	for (; it != lst.end(); ++it)
	{
		if (*it < prev)
			return 0;
		prev = *it;
	}
	return 1;
}

void PmergeMe::sortVector()
{
	if (_vec.size() < 2 || isVecSorted(_vec))
		return ;
	// Implement sorting algorithm here
}

void PmergeMe::sortList()
{
	if (_list.size() < 2 || isListSorted(_list))
		return ;
	// Implement sorting algorithm here
}

std::vector<int> PmergeMe::getVector() const
{
	return _vec;
}

std::list<int> PmergeMe::getList() const
{
	return _list;
}