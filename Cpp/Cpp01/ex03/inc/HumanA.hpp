/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:04:19 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/18 12:29:35 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:

		std::string _name;
		Weapon _weapon;

	public:

		/**
		 * @brief Construct a new Human A object
		 * 
		 * @param weapon 
		 */
		HumanA(Weapon weapon);

		/**
		 * @brief Displays attacks message
		 * 
		 */
		void	attack();
};