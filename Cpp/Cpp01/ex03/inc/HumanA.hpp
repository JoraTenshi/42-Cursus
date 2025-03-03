/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:04:19 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/24 13:03:05 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:

		std::string _name;
		Weapon *_weapon;

	public:

		/**
		 * @brief Construct a new Human A object with parameters of name and weapon
		 * 
		 * @param name, weapon 
		 */
		HumanA(std::string name, Weapon &weapon);

		/**
		 * @brief Destroy the Human A object
		 * 
		 */
		~HumanA();

		/**
		 * @brief Displays attacks message
		 * 
		 */
		void	attack() const;
};

#endif