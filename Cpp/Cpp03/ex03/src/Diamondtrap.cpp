/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:19:30 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:13:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Diamondtrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = "defaultDiamond";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) : ClapTrap(DiamondTrap), ScavTrap(DiamondTrap), FragTrap(DiamondTrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = DiamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &DiamondTrap)
	{
		this->_name = DiamondTrap._name;
		this->_hitPoints = DiamondTrap._hitPoints;
		this->_energyPoints = DiamondTrap._energyPoints;
		this->_attackDamage = DiamondTrap._attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name: " << this->_name << std::endl;
	std::cout << "My ClapTrap name: " << ClapTrap::_name << std::endl;
}