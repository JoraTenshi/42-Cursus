/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:56:03 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:15 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Scavtrap.hpp"

Scavtrap::Scavtrap() : Claptrap()
{
	std::cout << "Scavtrap default constructor called" << std::endl;
	_name = "Scavtrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

Scavtrap::Scavtrap(std::string name) : Claptrap(name)
{
	std::cout << "Scavtrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

Scavtrap::Scavtrap(const Scavtrap &scavtrap) : Claptrap(scavtrap)
{
	std::cout << "Scavtrap copy constructor called" << std::endl;
	*this = scavtrap;
}

Scavtrap::~Scavtrap()
{
	std::cout << "Scavtrap destructor called" << std::endl;
}

Scavtrap &Scavtrap::operator=(const Scavtrap &scavtrap)
{
	std::cout << "Scavtrap copy assignment operator called" << std::endl;
	if (this != &scavtrap)
	{
		_name = scavtrap._name;
		_hitPoints = scavtrap._hitPoints;
		_energyPoints = scavtrap._energyPoints;
		_attackDamage = scavtrap._attackDamage;
	}
	return *this;
}

void Scavtrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "Scavtrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void Scavtrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " is dead and cannot guard" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "Scavtrap " << this->_name << " has no energy points left nad cannot guard" << std::endl;
		return ;
	}
	std::cout << "Scavtrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}