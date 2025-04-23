/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:31:01 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/23 11:41:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t len, void (*f)(T &))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}