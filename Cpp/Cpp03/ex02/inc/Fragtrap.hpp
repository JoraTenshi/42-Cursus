/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 18:09:12 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Claptrap.hpp"

class Fragtrap : public Claptrap
{
	public:
		/**
		 * @brief Construct a new Fragtrap object
		 * 
		 */
		Fragtrap();

		/**
		 * @brief Construct a new Fragtrap object
		 * 
		 * @param name 
		 */
		Fragtrap(std::string name);

		/**
		 * @brief Construct a new Fragtrap object
		 * 
		 * @param src 
		 */
		Fragtrap(const Fragtrap &fragtrap);

		/**
		 * @brief Destroy the Fragtrap object
		 * 
		 */
		~Fragtrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Fragtrap& 
		 */
		Fragtrap &operator=(const Fragtrap &fragtrap);

		/**
		 * @brief He is a very good boy and highfives
		 * 
		 */
		void highFivesGuys(void);
};