/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:11 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/15 09:57:11 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		/**
		 * @brief Construct a new Cat object
		 * 
		 */
		Cat();
		
		/**
		 * @brief Construct a new Cat object
		 * 
		 * @param src 
		 */
		Cat(const Cat &src);
		
		/**
		 * @brief Destroy the Cat object
		 * 
		 */
		~Cat();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src
		 * @return Cat& 
		 */
		Cat &operator=(const Cat &src);
		
		/**
		 * @brief Display the sound of the animal
		 * 
		 */
		void makeSound() const;
};