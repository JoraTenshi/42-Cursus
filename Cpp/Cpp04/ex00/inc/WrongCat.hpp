/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:23:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/15 09:58:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		/**
		 * @brief Construct a new WrongCat object
		 * 
		 */
		WrongCat();
		
		/**
		 * @brief Construct a new WrongCat object
		 * 
		 * @param src 
		 */
		WrongCat(const WrongCat &src);
		
		/**
		 * @brief Destroy the WrongCat object
		 * 
		 */
		~WrongCat();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return WrongCat& 
		 */
		WrongCat &operator=(const WrongCat &src);
		
		/**
		 * @brief Display the sound of the animal
		 * 
		 */
		void makeSound() const;
};