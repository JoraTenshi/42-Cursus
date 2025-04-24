/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:08:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 14:45:42 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>
#include "colors.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();

		MutantStack &operator=(const MutantStack &src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}