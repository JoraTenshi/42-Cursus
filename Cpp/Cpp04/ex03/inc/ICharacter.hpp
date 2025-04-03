/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:37:31 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 15:08:53 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:

		/**
		 * @brief Construct a new ICharacter object
		 * 
		 */
		virtual ~ICharacter() {}
		
		/**
		 * @brief Get the Name object
		 * 
		 * @return std::string const& 
		 */
		virtual std::string const & getName() const = 0;
		
		/**
		 * @brief Equip a new AMateria object
		 * 
		 * @param m 
		 */
		virtual void equip(AMateria* m) = 0;

		/**
		 * @brief Unequip a AMateria object
		 * 
		 * @param idx 
		 */
		virtual void unequip(int idx) = 0;

		/**
		 * @brief Use a AMateria object
		 * 
		 * @param idx 
		 * @param target 
		 */
		virtual void use(int idx, ICharacter& target) = 0;
};