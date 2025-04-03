/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:56:06 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 11:40:24 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Claptrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		/**
		 * @brief Construct a new ScavTrap object
		 * 
		 */
		ScavTrap();

		/**
		 * @brief Construct a new ScavTrap object
		 * 
		 * @param name 
		 */
		ScavTrap(std::string name);

		/**
		 * @brief Construct a new ScavTrap object
		 * 
		 * @param src 
		 */
		ScavTrap(const ScavTrap &ScavTrap);

		/**
		 * @brief Destroy the ScavTrap object
		 * 
		 */
		~ScavTrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return ScavTrap& 
		 */
		ScavTrap &operator=(const ScavTrap &ScavTrap);

		/**
		 * @brief 
		 * 
		 * @param target 
		 */
		void attack(const std::string &target);

		/**
		 * @brief 
		 * 
		 */
		void guardGate();
};
