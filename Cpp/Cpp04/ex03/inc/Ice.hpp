/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:47 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:47:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	
	/**
	 * @brief Construct a new Ice object
	 * 
	 */
		Ice();

		/**
		 * @brief Construct a new Ice object
		 * 
		 * @param src 
		 */
		Ice(Ice const & src);

		/**
		 * @brief Destroy the Ice object
		 * 
		 */
		virtual ~Ice();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Ice& 
		 */
		Ice & operator=(Ice const & src);
		
		/**
		 * @brief Clone the AMateria object
		 * 
		 * @return std::string 
		 */
		virtual AMateria* clone() const;

		/**
		 * @brief Use the ice 
		 * 
		 * @param target 
		 */
		virtual void use(ICharacter& target);
};