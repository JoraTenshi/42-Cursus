/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:08 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/16 13:29:33 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include "colors.h"

#define INT_MAX 	std::numeric_limits<int>::max()
#define INT_MIN 	std::numeric_limits<int>::min()
#define FLOAT_MAX 	std::numeric_limits<float>::max()
#define FLOAT_MIN 	std::numeric_limits<float>::min()
#define DOUBLE_MAX 	std::numeric_limits<double>::max()
#define DOUBLE_MIN 	std::numeric_limits<double>::min()


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		
	public:
		static void convert(const std::string &toConvert);
};