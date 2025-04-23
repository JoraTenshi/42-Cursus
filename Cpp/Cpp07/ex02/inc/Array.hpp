/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:43:50 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/23 11:57:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{
	private:
		int		_size;
		T	*_array;
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		Array &operator=(const Array &src);

		T &operator[](int index);
		int size() const;
};

template<typename T>
Array<T>::Array() : _size(0), _array(new T(0)){}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]){}

template<typename T>
Array<T>::Array(const Array &src) : _size(src._size), _array(new T[src._size])
{
	for (int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _array;
		_size = src._size;
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw std::exception();
	return _array[index];
}

template<typename T>
int Array<T>::size() const
{
	return _size;
}