/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:17:07 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/03 11:38:44 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Sed.hpp"

Sed::Sed(std::string filename)
{
	_filename = filename;
	std::cout << "Sed has been created" << std::endl;
}

Sed::~Sed()
{
	std::cout << "Sed had been destroyed" << std::endl;
}

static std::string changeString(std::string aux, std::string s1, std::string s2)
{
	int	pos = 0;

	while ((pos = aux.find(s1, pos)) > -1)
	{
		if (pos >= 0)
		{
			aux.erase(pos, s1.length());
			aux.insert(pos, s2);
			pos += s2.length();	
		}
	}
	return (aux);
}

void	Sed::replace(std::string s1, std::string s2)
{
	std::string aux;

	std::ifstream	fdin;
	std::ofstream	fdout;
	fdin.open(_filename.c_str());
	fdout.open((_filename + ".replace").c_str());
	if (fdin.is_open() && fdout.is_open())
	{
		while (std::getline(fdin, aux))
		{
			aux = changeString(aux, s1, s2);
			fdout << aux << std::endl;
		}
		fdin.close();
		fdout.close();
	}
	else
		std::cerr << "Not able to open file or files" << std::endl;
}
