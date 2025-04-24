/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:26:52 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/24 11:39:24 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "colors.hpp"

template <typename T>
void easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cout << RED << "Value not found: " << value << DEFAULT << std::endl;
	else
		std::cout << PURPLE << "Value found: " << *it << DEFAULT << std::endl;
}
