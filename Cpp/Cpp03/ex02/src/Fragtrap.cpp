/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 18:11:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fragtrap.hpp"

Fragtrap::Fragtrap() : Claptrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Default Fragtrap constructor called" << std::endl;
}

Fragtrap::Fragtrap(std::string name) : Claptrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Fragtrap constructor called" << std::endl;
}

Fragtrap::Fragtrap(const Fragtrap &fragtrap) : Claptrap(fragtrap)
{
	this->_hitPoints = fragtrap._hitPoints;
	this->_energyPoints = fragtrap._energyPoints;
	this->_attackDamage = fragtrap._attackDamage;
	std::cout << "Fragtrap copy constructor called" << std::endl;
}

Fragtrap::~Fragtrap()
{
	std::cout << "Fragtrap destructor called" << std::endl;
}

Fragtrap &Fragtrap::operator=(const Fragtrap &fragtrap)
{
	if (this != &fragtrap)
	{
		this->_name = fragtrap._name;
		this->_hitPoints = fragtrap._hitPoints;
		this->_energyPoints = fragtrap._energyPoints;
		this->_attackDamage = fragtrap._attackDamage;
	}
	std::cout << "Fragtrap assignment operator called" << std::endl;
	return (*this);
}

void Fragtrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Fragtrap " << this->_name << " is dead and can't highfive!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "Fragtrap " << this->_name << " is out of energy and can't highfive!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "Fragtrap " << this->_name << " is highfiving!" << std::endl;
}