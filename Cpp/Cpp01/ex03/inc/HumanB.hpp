/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:04:25 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/24 13:10:27 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:

		std::string _name;
		Weapon *_weapon;

	public:

		/**
		 * @brief Construct a new Human B object
		 * 
		 */
		HumanB(std::string name);

		/**
		 * @brief Destroy the Human B object
		 * 
		 */
		~HumanB();

		/**
		 * @brief Displays attacks message
		 * 
		 */
		void	attack() const;

		/**
		 * @brief Set the Weapon object
		 * 
		 * @param weapon 
		 */
		void	setWeapon(Weapon &weapon);
};

#endif