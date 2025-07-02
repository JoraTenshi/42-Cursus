/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:58:03 by jcallejo          #+#    #+#             */
/*   Updated: 2025/07/02 12:04:22 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ParsedCommand 
{
    std::string prefix;              // Optional, starts with ':' (usually empty from clients)
    std::string command;             // The command name, e.g. "JOIN", "PRIVMSG"
    std::vector<std::string> args;   // Command arguments
};

class Parser 
{
	private:
    	std::vector<std::string> split(const std::string& str, char delimiter) const;
	
	public:
		Parser();
		~Parser();

		ParsedCommand parseLine(const std::string& line) const;
};
