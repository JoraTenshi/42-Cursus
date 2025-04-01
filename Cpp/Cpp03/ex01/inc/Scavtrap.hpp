/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:56:06 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Claptrap.hpp"

class Scavtrap : public Claptrap
{
	public:
		/**
		 * @brief Construct a new Scavtrap object
		 * 
		 */
		Scavtrap();

		/**
		 * @brief Construct a new Scavtrap object
		 * 
		 * @param name 
		 */
		Scavtrap(std::string name);

		/**
		 * @brief Construct a new Scavtrap object
		 * 
		 * @param src 
		 */
		Scavtrap(const Scavtrap &scavtrap);

		/**
		 * @brief Destroy the Scavtrap object
		 * 
		 */
		~Scavtrap();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Scavtrap& 
		 */
		Scavtrap &operator=(const Scavtrap &scavtrap);

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
