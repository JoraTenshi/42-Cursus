/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:39:58 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "Colors.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];

	public:
		/**
		 * @brief Construct a new Character object
		 * 
		 */
		Character();

		/**
		 * @brief Construct a new Character object
		 * 
		 * @param name 
		 */
		Character(std::string const & name);

		/**
		 * @brief Construct a new Character object
		 * 
		 * @param src 
		 */
		Character(Character const & src);

		/**
		 * @brief Destroy the Character object
		 * 
		 */
		virtual ~Character();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Character& 
		 */
		Character & operator=(Character const & src);
		
		/**
		 * @brief Get the Name object
		 * 
		 * @return std::string const& 
		 */
		std::string const & getName() const;
		
		/**
		 * @brief Equip the Materia object
		 * 
		 * @param index 
		 * @return AMateria* 
		 */
		void equip(AMateria* m);

		/**
		 * @brief Unequip the Materia object
		 * 
		 * @param index 
		 */
		void unequip(int idx);

		/**
		 * @brief Use the Materia object
		 * 
		 * @param index 
		 * @param target 
		 */
		void use(int idx, ICharacter& target);
};