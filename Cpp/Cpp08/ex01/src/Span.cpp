/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:00:29 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 13:45:42 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : _n(0), _size(0) {}

Span::Span(unsigned int n) : _n(n), _size(0) {}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_size = src._size;
		this->_list = src._list;
	}
	return *this;
}

static void correctLength(Span &span)
{
	if (span.getSize() > span.getN())
		throw std::out_of_range("Impossible to get span, list is full");
	else if (span.getSize() <= 1)
		throw std::length_error("Impossible to get span, list is empty or has only one element");
}

void Span::addNumber(int n)
{
	if (this->_size < this->_n)
	{
		this->_list.push_back(n);
		this->_size++;
	}
	else
		std::cout << RED << ("Impossible to add number, list is full") << DEFAULT << std::endl;
}

int Span::shortestSpan()
{
	std::list<int> list = this->_list;
	std::list<int> diff;
	try
	{
		correctLength(*this);
		list.sort();
		std::adjacent_difference(list.begin(), list.end(), std::back_inserter(diff));
		return (*std::min_element(diff.begin(), diff.end()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

}

int Span::longestSpan()
{
	std::list<int> list = this->_list;
	
	try
	{
	correctLength(*this);
	list.sort();
	return (std::abs(list.back() - list.front()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}

int Span::getN() const
{
	return this->_n;
}

int Span::getSize() const
{
	return this->_size;
}

std::list<int> Span::getList() const
{
	return this->_list;
}

void Span::fillRange()
{
	for (unsigned int i = _size; i < _n; i++)
		_list.push_back(rand() % 1000);
	_size = _n;
}

std::ostream &operator<<(std::ostream &out, const Span &span)
{

	std::list<int>	aux = span.getList();
	for (std::list<int>::iterator it = aux.begin(); it != aux.end(); it++)
		out << *it << " ";
	return (out);
}