/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:26:34 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:12:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = src._type;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & src)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << DEFAULT << std::endl;
}