/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:20:17 by jcallejo          #+#    #+#             */
/*   Updated: 2025/07/02 11:22:22 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server/Server.hpp"

bool isValidPort(const std::string& portStr) 
{
    for (size_t i = 0; i < portStr.length(); ++i)
{
        if (!isdigit(portStr[i]))
            return false;
    }

    int port = std::atoi(portStr.c_str());
    return port > 0 && port <= 65535;
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
	{
        std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }

    std::string portStr = argv[1];
    std::string password = argv[2];

    if (!isValidPort(portStr)) 
	{
        std::cerr << "Error: Invalid port number." << std::endl;
        return 1;
    }

    int port = std::atoi(portStr.c_str());
	
    try 
	{
        Server server(port, password);
        server.run(); // This will start listening and processing connections
    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
