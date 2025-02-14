/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:45 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/14 10:56:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Phonebook.hpp"

int	main()
{
	Phonebook	phonebook;
	std::string	input;
	bool		exit;
	
	phonebook.displayCommands();
	do {
		exit = false;
		std::cout << "Command: " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		std::cout << std::flush;
		if (input.compare("ADD") == 0)
		{
			phonebook.addContact();
		}
		else if (input.compare("SEARCH") == 0)
		{
			if (phonebook.getMaxIndex() == -1)
				std::cout << "Phonebook is empty, please add a contact first" << std::endl;
			else
			{
				phonebook.printTable();
				phonebook.printContact(phonebook.readIndex());
				std::cout << std::flush;
			}
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting program." << std::endl;
			exit = true;
		}
	} while(!exit);
	return 0;
}