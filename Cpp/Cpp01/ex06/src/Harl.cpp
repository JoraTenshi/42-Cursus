/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:56 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/06 11:30:49 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
	std::cout << "Hello, I am Harl" << std::endl;
}

Harl::~Harl()
{
	std::cout << "I have to go, doctor's appointment" << std::endl;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG_MSG << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl << INFO_MSG << std::endl;	
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl << WARNING_MSG << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl << ERROR_MSG << std::endl;
}

static int	strToLevel(std::string level)
{
	if (!level.compare(DEBUG))
		return (DEBUG_LVL);
	else if (!level.compare(INFO))
		return (INFO_LVL);
	else if (!level.compare(WARNING))
		return (WARNING_LVL);
	else if (!level.compare(ERROR))
		return (ERROR_LVL);
	return (-1);
}

void	Harl::complain(std::string level)
{
	int	lvl = strToLevel(level);

	switch (lvl)
	{
		case DEBUG_LVL:
			debug();
		case INFO_LVL:
			info();
		case WARNING_LVL:
			warning();
		case ERROR_LVL:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
