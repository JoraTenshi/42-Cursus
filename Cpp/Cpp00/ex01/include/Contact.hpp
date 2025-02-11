/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:43 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/11 11:19:13 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
	
	/**
	 * @brief Construct a new Contact object
	 * 
	 */
		Contact();

	/**
	 * @brief Get the Index object
	 * 
	 * @return int 
	 */
		int	getIndex() const;

	/**
	 * @brief Creates a new Contact object
	 * 
	 * @param index 
	 */
		void newContact(int index);

	/**
	 * @brief Gets input to add to new contact
	 * 
	 * @param prompt 
	 * @return std::string 
	 */
		std::string getInput(std::string prompt) const;
		
	/**
	 * @brief Prints contact 
	 * 
	 */
		void	printContact() const;

	/**
	 * @brief Prints table lines
	 * 
	 */
		void	printTableLine() const;

	/**
	 * @brief Prints the certain string
	 * 
	 * @param str 
	 */
		std::string	ft_print(std::string str) const;
};

#endif