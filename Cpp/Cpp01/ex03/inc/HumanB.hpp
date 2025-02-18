/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:04:25 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/18 12:29:31 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:

		std::string _name;
		Weapon _weapon;

	public:

		/**
		 * @brief Construct a new Human B object
		 * 
		 */
		HumanB();

		/**
		 * @brief Displays attacks message
		 * 
		 */
		void	attack();
};