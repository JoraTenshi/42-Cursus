/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:18:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:03:47 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

class Animal
{
	protected:
		std::string _type;

	public:

		/**
		 * @brief Construct a new Animal object
		 * 
		 */
		Animal();

		/**
		 * @brief Construct a new Animal object
		 * 
		 * @param type 
		 */
		Animal(std::string type);

		/**
		 * @brief Construct a new Animal object
		 * 
		 * @param src 
		 */
		Animal(const Animal &src);

		/**
		 * @brief Destroy the Animal object
		 * 
		 */
		virtual ~Animal();
		
		/**
		 * @brief Overload of = opertaor
		 * 
		 * @param rhs 
		 * @return Animal& 
		 */
		Animal &operator=(const Animal &src);

		/**
		 * @brief Display the sound of the animal
		 * 
		 */
		virtual void makeSound() const;

		/**
		 * @brief Get the Type object
		 * 
		 * @return std::string 
		 */
		std::string getType() const;

		/**
		 * @brief Set the Type object
		 * 
		 * @param type 
		 */
		void setType(std::string type);
};