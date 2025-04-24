/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:44:54 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 12:54:59 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include "colors.hpp"

class Span
{
	private:
		unsigned int		_n;
		unsigned int		_size;
		std::list<int>		_list;
		
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);
		
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		int 	getN() const;
		int 	getSize() const;
		std::list<int>	getList() const;
		void    fillRange();
};

std::ostream & operator <<(std::ostream &out, const Span &span);