/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:04:11 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/18 12:27:09 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
	private:
		std::string	_type;
		
	public:
	
		/**
		 * @brief Construct a new Weapon object
		 * 
		 */
		Weapon();

		/**
		 * @brief Destroy the Weapon object
		 * 
		 */
		~Weapon();
		
		/**
		 * @brief Get the Type object
		 * 
		 * @return std::string 
		 */
		const std::string	getType() const;

		/**
		 * @brief Set the Type object
		 * 
		 */
		void		setType(std::string type);
};