/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:43:09 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "Colors.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _inventory[4];

	public:

		/**
		 * @brief Construct a new Materia Source object
		 * 
		 */
		MateriaSource();

		/**
		 * @brief Construct a new Materia Source object
		 * 
		 * @param src 
		 */
		MateriaSource(MateriaSource const & src);

		/**
		 * @brief Destroy the Materia Source object
		 * 
		 */
		virtual ~MateriaSource();

		/**
		 * @brief Overload of = operator
		 * 
		 * @param src 
		 * @return MateriaSource& 
		 */
		MateriaSource & operator=(MateriaSource const & src);

		/**
		 * @brief Learn the Materia object
		 * 
		 * @param idx 
		 * @return AMateria* 
		 */
		void learnMateria(AMateria* m);

		/**
		 * @brief Create a new Materia object
		 * 
		 * @param type 
		 * @return AMateria* 
		 */
		AMateria* createMateria(std::string const & type);
};