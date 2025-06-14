/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:03:24 by jcallejo          #+#    #+#             */
/*   Updated: 2025/06/10 11:41:52 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments." << DEFAULT << std::endl;
		return 1;
	}
	
	if (argv[1][0] == '\0')
	{
		std::cerr << RED << "Error: Empty expression." << DEFAULT << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.calculate(argv[1]);
	
	return 0;
}