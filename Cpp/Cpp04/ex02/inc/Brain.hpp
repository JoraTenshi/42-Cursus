/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:55:03 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:56:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:

		/**
		 * @brief Construct a new Brain object
		 * 
		 */
		Brain();

		/**
		 * @brief Construct a new Brain object
		 * 
		 * @param src 
		 */
		Brain(const Brain &src);

		/**
		 * @brief Destroy the Brain object
		 * 
		 */
		virtual ~Brain();
		
		/**
		 * @brief Overload of = opertaor
		 * 
		 * @param rhs 
		 * @return Brain& 
		 */
		Brain &operator=(const Brain &src);

		/**
		 * @brief Adds an idea to ideas array
		 * 
		 * @param idea 
		 * @return true 
		 * @return false 
		 */
		bool addIdea(std::string idea);

		/**
		 * @brief Get the idea at index
		 * 
		 * @param index 
		 * @return std::string 
		 */
		std::string getIdea(int index);
};