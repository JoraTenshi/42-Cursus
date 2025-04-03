/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:54:54 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 15:01:05 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "defaultMateria";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & src)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}