/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:59:15 by jcallejo          #+#    #+#             */
/*   Updated: 2025/05/07 11:05:12 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>
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

		void sortVector();
		void sortList();

		std::vector<int> getVector() const;
		std::list<int> getList() const;
		
};

std::ostream &operator<<(std::ostream &o, const PmergeMe &src);
std::ostream &operator<<(std::ostream &o, const std::vector<int> &vec);
std::ostream &operator<<(std::ostream &o, const std::list<int> &lst);