/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:22:59 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/18 11:38:13 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string _name;
		
	public:
		
		/**
		 * @brief Construct a new Zombie object
		 * 
		 */
		Zombie();

		/**
		 * @brief Destroy the Zombie object
		 * 
		 */
		~Zombie();

		/**
		 * @brief Construct a new Zombie object with name
		 * 
		 * @param name 
		 */
		Zombie(std::string name);

		/**
		 * @brief Announces the zombie
		 * 
		 */
		void	announce() const;

		/**
		 * @brief Gives name to  a zombie
		 * 
		 * @param name 
		 */
		void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif