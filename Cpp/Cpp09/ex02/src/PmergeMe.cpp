/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:32 by jcallejo          #+#    #+#             */
/*   Updated: 2025/06/05 13:58:34 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	while (*argv)
	{
		_vec.push_back(atoi(*argv));
		_list.push_back(atoi(*argv));
		argv++;
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

static std::list<int> mergeList(std::list<int> list1, std::list<int> list2)
{
	std::list<int> tmp;

	while(!list1.empty() && !list2.empty())
	{
		if (list1.front() < list2.front())
		{
			tmp.push_back(list1.front());
			list1.pop_front();
		}
		else
		{
			tmp.push_back(list2.front());
			list2.pop_front();
		}
	}

	while (!list1.empty())
	{
		tmp.push_back(list1.front());
		list1.pop_front();
	}

	while (!list2.empty())
	{
		tmp.push_back(list2.front());
		list2.pop_front();
	}

	return tmp;
}

static std::vector<int> mergeVector(std::vector<int> vec1, std::vector<int> vec2)
{
	std::vector<int> tmp;

	while(!vec1.empty() && !vec2.empty())
	{
		if (vec1.front() < vec2.front())
		{
			tmp.push_back(vec1.front());
			vec1.erase(vec1.begin()+ 0);
		}
		else
		{
			tmp.push_back(vec2.front());
			vec2.erase(vec2.begin() + 0);
		}
	}

	while (!vec1.empty())
	{
		tmp.push_back(vec1.front());
		vec1.erase(vec1.begin() + 0);
	}

	while (!vec2.empty())
	{
		tmp.push_back(vec2.front());
		vec2.erase(vec2.begin() + 0);
	}

	return tmp;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> vec)
{
	if (vec.size() < 2)
		return vec;

	std::vector<int> vec1;
	
	for(size_t i = 0; i != vec.size() / 2; i++)
		vec1.push_back(vec[i]);

	std::vector<int> vec2;

	for(size_t i = vec.size() / 2; i != vec.size(); i++)
		vec2.push_back(vec[i]);

	vec1 = sortVector(vec1);
	vec2 = sortVector(vec2);
	
	return mergeVector(vec1, vec2);
}

std::list<int> PmergeMe::sortList(std::list<int> list)
{
	if (list.size() < 2)
		return list;
	std::list<int> list1, list2;
	std::list<int>::iterator it = list.begin();
	for (size_t i = 0; i < list.size() / 2; i++)
		list1.push_back(*it++);
	while (it != list.end())
	{
		list2.push_back(*it);
		it++;
	}
	list1 = sortList(list1);
	list2 = sortList(list2);
	return mergeList(list1, list2);
}

std::vector<int> PmergeMe::getVector() const
{
	return _vec;
}

std::list<int> PmergeMe::getList() const
{
	return _list;
}


std::ostream &operator<<(std::ostream &out, const std::vector<int> &v)
{
	std::vector<int>::const_iterator iterator = v.begin();
	std::vector<int>::const_iterator end = v.end();

	while (iterator != end)
	{
		out << *iterator;
		++iterator;
		if (iterator != end)
			out << " ";
	}
	return (out);
}

std::ostream &operator<<(std::ostream &out, const std::list<int> &l)
{
	std::list<int>::const_iterator iterator = l.begin();
	std::list<int>::const_iterator end = l.end();

	while (iterator != end)
	{
		out << *iterator;
		++iterator;
		if (iterator != end)
			out << " ";
	}
	return (out);
}