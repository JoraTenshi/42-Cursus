/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:34:00 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/25 12:44:43 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_parseCSV("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->_map = src.getMap();
	}
	return *this;
}

void BitcoinExchange::_parseCSV(const std::string &filename)
{
	std::ifstream stream;
	std::string line;
	std::string date;
	float value;

	stream.open(filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}
	while (std::getline(stream, line))
	{
		date = line.substr(0, line.find(','));
		value = std::atof(line.substr(line.find(',') + 1).c_str());
		this->_map.insert(std::pair<std::string, float>(date, value));
	}
	stream.close();
}

bool BitcoinExchange::_isValidDate(const std::string &date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	if (month == 2 && day > 28 && year % 4 != 0)
		return false;
	if (month == 2 && day > 29 && year % 4 == 0)
		return false;
	return true;
}

bool BitcoinExchange::_isDateInCSV(const std::string &date)
{
	std::map<std::string, float>::const_iterator it = this->_map.find(date);
	if (it != this->_map.end())
		return true;
	return false;
}

void BitcoinExchange::_getLastValidDate(const std::string &date, float value)
{
	std::map<std::string, float>::const_iterator it = this->_map.lower_bound(date);
	if (it != this->_map.begin())
	{
		it--;
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
	else
	{
		std::cerr << "Error: no valid date found for " << date << std::endl;
	}
}

std::map<std::string, float> BitcoinExchange::getMap() const
{
	return this->_map;
}

void BitcoinExchange::processFile(const std::string &filename)
{
	std::ifstream	stream;
	std::string		line;
	std::string		date;
	float			value;

	stream.open(filename.c_str());
	if (!stream.is_open())
	{
		std::cerr << "Error: Couldn't open " << filename << std::endl;
		return ;
	}
	while (std::getline(stream, line))
	{
		if (line.empty() || line[0] == '#' || line == "date | value")
			continue ;
		date = line.substr(0, line.find(' '));
		value = atof(line.substr(line.find("|") + 1).c_str());
		if (line.find("|") == std::string::npos)
			std::cerr << RED << "Error: bad input => " << line << DEFAULT << std::endl;
		else if (value > 1000)
			std::cerr << RED << "Error: too large a number." << DEFAULT << std::endl;
		else if (value < 0)
			std::cerr << RED << "Error: not a positive number." << DEFAULT << std::endl;
		else if (!_isValidDate(date))
			std::cerr << RED << "Error: bad date => " << line << DEFAULT << std::endl;
		else if (_isDateInCSV(date))
			std::cerr << GREEN << date << " => " << value << " = " << _map[date] << DEFAULT << std::endl;
		else
			_getLastValidDate(date, value);
	}
	stream.close();
}

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &bitcoinexchange)
{
	const std::map<std::string, float>	data = bitcoinexchange.getMap();
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); it++)
		out << it->first << " " << it->second << std::endl;
	return (out);
}