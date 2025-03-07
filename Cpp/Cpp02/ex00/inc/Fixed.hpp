/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:56:42 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/07 12:00:28 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int 	_fracBit = 8;
		
	public:
	
		/**
		 * @brief Construct a new Fixed object
		 * 
		 */
		Fixed();
		
		/**
		 * @brief Construct a new Fixed object
		 * 
		 * @param fixed 
		 */
		Fixed(const Fixed &fixed);

		/**
		 * @brief Overload of = operator
		 * 
		 * @param fixed 
		 * @return Fixed& 
		 */
		Fixed & operator = (const Fixed &fixed);
		
		/**
		 * @brief Destroy the Fixed object
		 * 
		 */
		~Fixed();

		/**
		 * @brief Get the Raw Bits object
		 * 
		 * @return int 
		 */
		int	getRawBits( void ) const;

		/**
		 * @brief Set the Raw Bits object
		 * 
		 * @param raw 
		 */
		void	setRawBits ( int const raw );
};