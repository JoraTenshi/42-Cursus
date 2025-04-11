/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:22:52 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:12:15 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
	this->_type = src._type;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const & src)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << DEFAULT << std::endl;
}