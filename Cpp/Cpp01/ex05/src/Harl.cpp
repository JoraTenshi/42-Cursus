/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:56 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/06 11:04:05 by jcallejo         ###   ########.fr       */
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
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info()
{
	std::cout << INFO_MSG << std::endl;	
}

void	Harl::warning()
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error()
{
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string level)
{
	t_harl		response[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {DEBUG, INFO, WARNING, ERROR};
	int			i = 0;

	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*response[i])();
}
