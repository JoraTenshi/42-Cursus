/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:19:19 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 11:43:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Scavtrap.hpp"
#include "Fragtrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private: 
		std::string _name;
		
	public:
		/**
		 * @brief Construct a new DiamondTrap object
		 * 
		 */
		DiamondTrap();

		/**
		 * @brief Construct a new DiamondTrap object
		 * 
		 * @param name 
		 */
		DiamondTrap(std::string name);
		
		/**
		 * @brief Construct a new DiamondTrap object
		 * 
		 * @param DiamondTrap 
		 */
		DiamondTrap(const DiamondTrap &DiamondTrap);

		/**
		 * @brief Destroy the DiamondTrap object
		 * 
		 */
		~DiamondTrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param DiamondTrap 
		 * @return DiamondTrap& 
		 */
		DiamondTrap &operator=(const DiamondTrap &DiamondTrap);

		/**
		 * @brief Attack function inherited from ScavTrap
		 * 
		 */
		using ScavTrap::attack;
		
		/**
		 * @brief WHo am I? Who knows!
		 * 
		 */
		void whoAmI();
};