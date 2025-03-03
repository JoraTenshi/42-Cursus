/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:19 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/03 11:21:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	private:
		std::string _filename;
	
	public:
	
		/**
		 * @brief Construct a new Sed object
		 * 
		 * @param filename 
		 */
		Sed(std::string filename);
		
		/**
		 * @brief Destroy the Sed object
		 * 
		 */
		~Sed();

		/**
		 * @brief Replaces s1 with s2
		 * 
		 * @param s1 
		 * @param s2 
		 */
		void	replace(std::string s1, std::string s2);
};

#endif