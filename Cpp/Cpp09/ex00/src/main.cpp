/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:33:57 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/25 12:38:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED "Usage: ./bitcoin [filename]" DEFAULT << std::endl;
		return (1);
	}

	BitcoinExchange	btc = BitcoinExchange();
	btc.processFile(argv[1]);

	return (0);
}