/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:22:09 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/15 10:00:43 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		/**
		 * @brief Construct a new WrongAnimal object
		 * 
		 */
		WrongAnimal();
		
		/**
		 * @brief Construct a new WrongAnimal object
		 * 
		 * @param type 
		 */
		WrongAnimal(std::string type);
		
		/**
		 * @brief Construct a new WrongAnimal object
		 * 
		 * @param src 
		 */
		WrongAnimal(const WrongAnimal &src);
		
		/**
		 * @brief Destroy the WrongAnimal object
		 * 
		 */
		virtual ~WrongAnimal();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return WrongAnimal& 
		 */
		WrongAnimal &operator=(const WrongAnimal &src);
		
		/**
		 * @brief Display the sound of the animal
		 * 
		 */
		void makeSound() const;

		/**
		 * @brief Get the type of the animal
		 * 
		 * @return std::string 
		 */
		std::string getType() const;
};