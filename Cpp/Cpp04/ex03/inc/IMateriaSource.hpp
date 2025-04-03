/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:42:42 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 14:36:27 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	public:

		/**
		 * @brief Destroy the IMateriaSource object
		 * 
		 */
		virtual ~IMateriaSource() {}
		
		/**
		 * @brief Learn a new AMateria object
		 * 
		 * @param m 
		 */
		virtual void learnMateria(AMateria* m) = 0;

		/**
		 * @brief Create a new AMateria object
		 * 
		 * @param type 
		 * @return AMateria* 
		 */
		virtual AMateria* createMateria(std::string const & type) = 0;
};	