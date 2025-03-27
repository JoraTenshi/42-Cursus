/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:22:38 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/26 12:42:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

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
		 * @brief Construct a new Fixed object
		 * 
		 * @param convert 
		 */
		Fixed(const float value);

		
		/**
		 * @brief Construct a new Fixed object
		 * 
		 * @param convert 
		 */
		Fixed(const int value);
		
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
		
		/**
		 * @brief Converts fixed point value to float
		 * 
		 * @return float 
		 */
		float	toFloat( void ) const;

		/**
		 * @brief Converts fixed point value to int
		 * 
		 * @return int 
		 */
		int		toInt( void ) const;

		/**
		 * @brief Overload of = operator
		 * 
		 * @param fixed 
		 * @return Fixed& 
		 */
		Fixed & operator= (const Fixed &fixed);
		
		Fixed operator+ (const Fixed &fixed);
		Fixed operator- (const Fixed &fixed);
		Fixed operator* (const Fixed &fixed);
		Fixed operator/ (const Fixed &fixed);

		Fixed & operator++ (void);
		Fixed & operator-- (void);
		Fixed operator++ (int);
		Fixed operator-- (int);

		bool operator> (const Fixed &fixed);
		bool operator< (const Fixed &fixed);
		bool operator>= (const Fixed &fixed);
		bool operator<= (const Fixed &fixed);
		bool operator== (const Fixed &fixed);
		bool operator!= (const Fixed &fixed);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

/**
 * @brief Overload of << operator
 * 
 * @param out 
 * @param fixed 
 * @return std::ostream& 
 */
std::ostream& operator<< (std::ostream &out, const Fixed &fixed);