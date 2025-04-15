/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:39 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/15 09:57:07 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		/**
		 * @brief Construct a new Dog object
		 * 
		 */
		Dog();
		
		/**
		 * @brief Construct a new Dog object
		 * 
		 * @param src 
		 */
		Dog(const Dog &src);
		
		/**
		 * @brief Destroy the Dog object
		 * 
		 */
		~Dog();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Dog& 
		 */
		Dog &operator=(const Dog &src);
		
		/**
		 * @brief Display the sound of the animal
		 * 
		 */
		void makeSound() const;
};