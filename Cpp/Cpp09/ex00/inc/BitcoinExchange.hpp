/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:02:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/25 12:36:41 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include "colors.hpp"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _map;
		void _parseCSV(const std::string& filename);
		bool _isValidDate(const std::string& date);
		bool _isDateInCSV(const std::string& date);
		void _getLastValidDate(const std::string& date, float value);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		
		BitcoinExchange& operator=(const BitcoinExchange& src);
		
		std::map<std::string, float> getMap() const;
		void processFile(const std::string& filename);
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& src);