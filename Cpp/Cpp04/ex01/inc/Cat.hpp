/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:21:11 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:00:55 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
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
		 * @brief Construct a new Cat object
		 * 
		 * @param brain 
		 */
		Cat(Brain &brain);
		
		/**
		 * @brief Destroy the Cat object
		 * 
		 */
		virtual ~Cat();
		
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