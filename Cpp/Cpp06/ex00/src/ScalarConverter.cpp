/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:17:42 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/22 15:33:42 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) 
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) 
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	(void)src;
	return *this;
}


static int myInt(std::string toConvert)
{
	int 	i = 0;
	int 	len = toConvert.length();
	long	n;
	
	if (toConvert[i] == '-')
		i++;
	while (i < len && std::isdigit(toConvert[i]))
		i++;
	if (i != len)
		return 0;
	n = atol(toConvert.c_str());
	if (n < 33 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	if (n < INT_MIN || n > INT_MAX)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (n < -(std::numeric_limits<float>::max()) || n > (std::numeric_limits<float>::max()))
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	if (n < -(std::numeric_limits<double>::max()) || n > (std::numeric_limits<double>::max()))
		std::cout << "double: overflow" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
	return 1;
}

static int myChar(std::string toConvert)
{
	if (toConvert.length() != 1 || std::isdigit(toConvert[0]))
		return 0;
	std::cout << "char: " << toConvert << std::endl;
	std::cout << "int: " << static_cast<int>(toConvert[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(toConvert[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(toConvert[0]) << ".0" << std::endl;
	
	return 1;
}

static int myFloat(std::string toConvert)
{
	int 	i = 0;
	int 	len = toConvert.length();
	double	n;
	
	if (toConvert[i] == '-')
		i++;
	while (i < len && (std::isdigit(toConvert[i]) || toConvert[i] == '.' || toConvert[i] == 'f')) 
		i++;
	if (i != len)
		return 0;
	n = atof(toConvert.c_str());
	if (n < 33 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	if (n < INT_MIN || n > INT_MAX)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (n < -(std::numeric_limits<float>::max()) || n > (std::numeric_limits<float>::max()))
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	if (n < -(std::numeric_limits<double>::max()) || n > (std::numeric_limits<double>::max()))
		std::cout << "double: overflow" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(n) << std::endl;
	return 1;
}

static int special(const std::string &toConvert)
{
	if (toConvert == "nan" || toConvert == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return 1;
	}
	else if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "inf" || toConvert == "-inf" ||toConvert == "-nan" || toConvert == "-nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 1;
	}

	return 0;
}

void ScalarConverter::convert(const std::string &toConvert)
{
	if (special(toConvert) || myInt(toConvert) || myChar(toConvert) || myFloat(toConvert))
		return ;
	std::cout << "Error: Cannot convert" << std::endl;
}