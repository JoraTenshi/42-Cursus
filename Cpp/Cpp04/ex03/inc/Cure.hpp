/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:47:10 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	/**
	 * @brief Construct a new Cure object
	 * 
	 */
		Cure();

		/**
		 * @brief Construct a new Cure object
		 * 
		 * @param src 
		 */
		Cure(Cure const & src);

		/**
		 * @brief Destroy the Cure object
		 * 
		 */
		virtual ~Cure();
		
		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return Cure& 
		 */
		Cure & operator=(Cure const & src);
		
		/**
		 * @brief Clone the AMateria object
		 * 
		 * @return std::string 
		 */
		virtual AMateria* clone() const;

		/**
		 * @brief Use the cure 
		 * 
		 * @param target 
		 */
		virtual void use(ICharacter& target);
};