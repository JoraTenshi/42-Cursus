/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:22:37 by jcallejo          #+#    #+#             */
/*   Updated: 2025/01/30 12:22:38 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string s = argv[i];
			for(size_t j = 0; j < s.length(); j++)
				std::cout << (char)std::toupper(argv[i][j]);
			if (argv[i + 1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
