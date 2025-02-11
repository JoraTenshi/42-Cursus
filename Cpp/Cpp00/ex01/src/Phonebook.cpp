/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:47 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/11 13:24:31 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Phonebook.hpp"

Phonebook::Phonebook() {};

void	Phonebook::displayCommands() const
{
	std::cout << "Your available commmands are: " << std::endl;
	std::cout << "ADD: save a new contact." << std::endl;
	std::cout << "SEARCH: search for a contact in the phonebook." << std::endl;
	std::cout << "EXIT: exits the program and deletes information stored in it" << std::endl;
}

void	Phonebook::printTable() const
{
	std::cout << "|" << std::setw(9) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].printTableLine();
}

void	Phonebook::printContact(int index) const 
{
	contacts[index % 8].printContact();
}

void	Phonebook::addContact()
{
	int	maxIndex;

	maxIndex = this->getMaxIndex() + 1;
	contacts[maxIndex % 8].newContact(maxIndex);
}

int	Phonebook::getMaxIndex() const
{
	int	maxIndex = contacts[0].getIndex();

	for (int i = 0; i < 8; i++)
		if (contacts[i].getIndex() > maxIndex)
			maxIndex = contacts[i].getIndex();
	return maxIndex;
}

int	Phonebook::readIndex() const
{
	int				index;
	std::string		input;
	bool			valid;

		input = "";
	do {
		std::cout << "Input index: ";
		std::getline(std::cin, input);
		index = std::atoi(input.c_str());
		for (int i = 0; i < 8; i++)
		{
			if (index >= 0 && contacts[i].getIndex() == index)
			{
				valid = true;
				break;
			}
			else
				valid = false;
		}
					
	} while (!valid);
	return (index);
}