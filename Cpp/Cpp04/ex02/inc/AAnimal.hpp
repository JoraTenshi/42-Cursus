/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:18:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:12:55 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:

		/**
		 * @brief Construct a new AAnimal object
		 * 
		 */
		AAnimal();

		/**
		 * @brief Construct a new AAnimal object
		 * 
		 * @param type 
		 */
		AAnimal(std::string type);

		/**
		 * @brief Construct a new AAnimal object
		 * 
		 * @param src 
		 */
		AAnimal(const AAnimal &src);

		/**
		 * @brief Destroy the AAnimal object
		 * 
		 */
		virtual ~AAnimal();
		
		/**
		 * @brief Overload of = opertaor
		 * 
		 * @param rhs 
		 * @return Animal& 
		 */
		AAnimal &operator=(const AAnimal &src);

		/**
		 * @brief Display the sound of the AAnimal
		 * 
		 */
		virtual void makeSound() const = 0;

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