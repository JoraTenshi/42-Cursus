/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:15 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/23 13:00:49 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>
#include <sys/time.h>
#include "colors.hpp"

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::list<int> _list;
		
	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		std::vector<int> getVector() const;
		std::vector<int> sortVector(std::vector<int> vec);
		
		std::list<int> getList() const;
		std::list<int> sortList(std::list<int> list);
		
};

std::ostream &operator<<(std::ostream &o, const std::vector<int> &vec);
std::ostream &operator<<(std::ostream &o, const std::list<int> &lst);