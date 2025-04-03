/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:04:41 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Claptrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		/**
		 * @brief Construct a new FragTrap object
		 * 
		 */
		FragTrap();

		/**
		 * @brief Construct a new FragTrap object
		 * 
		 * @param name 
		 */
		FragTrap(std::string name);

		/**
		 * @brief Construct a new FragTrap object
		 * 
		 * @param src 
		 */
		FragTrap(const FragTrap &FragTrap);

		/**
		 * @brief Destroy the FragTrap object
		 * 
		 */
		~FragTrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return FragTrap& 
		 */
		FragTrap &operator=(const FragTrap &FragTrap);

		/**
		 * @brief He is a very good boy and highfives
		 * 
		 */
		void highFivesGuys(void);
};