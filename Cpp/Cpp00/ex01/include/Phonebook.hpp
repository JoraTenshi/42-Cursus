/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/11 13:24:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
	public:
	
	/**
	 * @brief Construct a new Phonebook object
	 * 
	 */
		Phonebook();

	/**
	 * @brief Displays initial commands
	 * 
	 */
		void	displayCommands() const;

	/**
	 * @brief Adds contact to phonebook
	 * 
	 */
		void	addContact();

	/**
	 * @brief Gets max index to either add at the end or replace old contact
	 * 
	 * @return int 
	 */
		int		getMaxIndex() const;

	/**
	 * @brief Prints contact by using module and calling Contact::printContact
	 * 
	 */
		void	printContact(int index) const;

	/**
	 * @brief Prints full contact table
	 * 
	 */
		void	printTable() const;

	/**
	 * @brief Reads input index and shows that contact
	 * 
	 * @return int 
	 */
		int		readIndex()	const;
};

#endif