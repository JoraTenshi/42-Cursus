/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:02:37 by jcallejo          #+#    #+#             */
/*   Updated: 2025/07/02 12:14:34 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {}

Parser::~Parser() {}

//Splits a string by a delimiter into a vector
std::vector<std::string> Parser::split(const std::string& str, char delimiter) const 
{
    std::vector<std::string> result;
    std::string temp;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) 
	{
        if (*it == delimiter) 
		{
            result.push_back(temp);
            temp.clear();
        } 
		else 
            temp += *it;
    }
    result.push_back(temp);
    return result;
}

// Main parsing function
ParsedCommand Parser::parseLine(const std::string& line) const 
{
    ParsedCommand cmd;
    std::string input = line;
    std::string::size_type pos = 0;

    //Check for prefix
    if (!input.empty() && input[0] == ':') 
	{
        pos = input.find(' ');
        if (pos != std::string::npos) 
		{
            cmd.prefix = input.substr(1, pos - 1); //Skip ':'
            input = input.substr(pos + 1);
        } 
		else
		{
            cmd.prefix = input.substr(1);
            return cmd;
        }
    }

    //Extract command
    pos = input.find(' ');
    if (pos != std::string::npos) 
	{
        cmd.command = input.substr(0, pos);
        input = input.substr(pos + 1);
    } 
	else 
	{
        cmd.command = input;
        return cmd;
    }

    //Parse arguments
    bool trailing = false;
    std::string arg;
    std::istringstream iss(input);

    while (iss >> arg) 
	{
        if (!trailing && arg[0] == ':') 
		{
            trailing = true;
            std::string trailingArg = arg.substr(1);
            std::string rest;
            std::getline(iss, rest);
            if (!rest.empty()) 
                trailingArg += rest;
            cmd.args.push_back(trailingArg);
            break;
        } 
		else 
            cmd.args.push_back(arg);
    }

    return cmd;
}
