/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:19:25 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:02 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "Colors.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	
	public:
	/**
	 * @brief Construct a new AMateria object
	 * 
	 */
		AMateria();

		/**
		 * @brief Construct a new AMateria object
		 * 
		 * @param type 
		 */
		AMateria(std::string const & type);

		/**
		 * @brief Construct a new AMateria object
		 * 
		 * @param src 
		 */
		AMateria(AMateria const & src);

		/**
		 * @brief Destroy the AMateria object
		 * 
		 */
		virtual ~AMateria();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return AMateria& 
		 */
		AMateria & operator=(AMateria const & src);

		/**
		 * @brief Get the Type object
		 * 
		 * @return std::string const& 
		 */
		std::string const & getType() const;

		/**
		 * @brief Clone the AMateria object
		 * 
		 * @return AMateria* 
		 */
		virtual AMateria* clone() const = 0;

		/**
		 * @brief Use the AMateria object
		 * 
		 * @param target 
		 */
		virtual void use(ICharacter& target);
};