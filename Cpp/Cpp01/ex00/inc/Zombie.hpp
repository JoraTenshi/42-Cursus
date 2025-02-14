/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:24:59 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/14 11:29:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
	private:
		std::string	name;

	public:

		/**
		 * @brief Construct a new Zombie object
		 * 
		 */
		Zombie();

		void	announce ( void );
		
		Zombie* newZombie (std::string name);

		void	randomChump (std::string name);
};

#endif