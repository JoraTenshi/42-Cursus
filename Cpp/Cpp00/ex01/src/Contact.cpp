/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:31 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/14 10:59:20 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact()
{
	this->index = -1;
	this->firstName = "";
	this->lastName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

int	Contact::getIndex()	const
{
	return (this->index);
}

std::string	Contact::ft_print(std::string str)	const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string	Contact::getInput(std::string prompt) const
{
	std::string input;
	bool		valid;

	input = "";
	do {
		if (input.empty())
		{
			std::cout << prompt << std::flush;
			std::getline(std::cin, input);
			if (std::cin.eof())
				return ("");
			if (std::cin.good() && !input.empty())
				valid = true;
			else
			{
				std::cin.clear();
				std::cout << "Invalid input, try again" << std::endl;
				valid = false;
			}
		}
	} while (!valid);
	return (input);
}

void	Contact::printTableLine() const
{
	if (index == -1)
		std::cout << "|" << std::setw(10) << std::flush;
	else
		std::cout << "|" << std::setw(9) << this->index << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(this->nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::printContact() const
{
	std::cout << "Contact nº " << index << ":" << std::endl;
	std::cout << "\tFirst name: " << firstName << std::endl;
	std::cout << "\tLast name: " << lastName << std::endl;
	std::cout << "\tNickname: " << nickname << std::endl;
	std::cout << "\tPhone number: " << phoneNumber << std::endl;
	std::cout << "\tDarkest secret: " << darkestSecret << std::endl;
}

void	Contact::newContact(int index)
{
	this->index = index;
	this->firstName = this->getInput("First name: ");
	this->lastName = this->getInput("Last name: ");
	this->nickname = this->getInput("Nickname: ");
	this->phoneNumber = this->getInput("Phone number: ");
	this->darkestSecret = this->getInput("Darkest secret: ");
}