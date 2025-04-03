/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:26:36 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:11:48 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal constructor called" << std::endl;
	this->_type = type;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}