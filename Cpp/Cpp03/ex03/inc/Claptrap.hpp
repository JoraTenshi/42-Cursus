/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:16:02 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 11:51:21 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;
	public:

		/**
		 * @brief Construct a new ClapTrap object
		 * 
		 */
		ClapTrap();

		/**
		 * @brief Construct a new ClapTrap object
		 * 
		 * @param name 
		 */
		ClapTrap(std::string name);

		/**
		 * @brief Construct a new ClapTrap object
		 * 
		 * @param src 
		 */
		ClapTrap(const ClapTrap &ClapTrap);

		/**
		 * @brief Destroy the ClapTrap object
		 * 
		 */
		~ClapTrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return ClapTrap& 
		 */
		ClapTrap &operator=(const ClapTrap &src);

		/**
		 * @brief Attack a target
		 * 
		 * @param target 
		 */
		void attack(const std::string &target);

		/**
		 * @brief Take damage
		 * 
		 * @param amount 
		 */
		void takeDamage(unsigned int amount);

		/**
		 * @brief Repair itself
		 * 
		 * @param amount 
		 */
		void beRepaired(unsigned int amount);

		/**
		 * @brief Get the Name object
		 * 
		 * @return std::string 
		 */
		std::string getName() const;

		/**
		 * @brief Get the Hit Points object
		 * 
		 * @return unsigned int 
		 */
		unsigned int getHitPoints() const;

		/**
		 * @brief Get the Energy Points object
		 * 
		 * @return unsigned int 
		 */
		unsigned int getEnergyPoints() const;

		/**
		 * @brief Get the Attack Damage object
		 * 
		 * @return unsigned int 
		 */
		unsigned int getAttackDamage() const;
};