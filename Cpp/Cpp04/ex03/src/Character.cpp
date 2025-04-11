/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:58:13 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:14:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "defaultCharacter";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name)
{
	std::cout << "Character constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character & Character::operator=(Character const & src)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << PURPLE << "Equipped " << m->getType() << " to " << this->_name << DEFAULT << std::endl;
			return;
		}
	}
	std::cout << RED << "Inventory is full" << DEFAULT << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Invalid index" << DEFAULT << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << RED << "No Materia to unequip" << DEFAULT << std::endl;
		return;
	}
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	std::cout << PURPLE << "Unequipped Materia from " << this->_name << DEFAULT << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Invalid index" << DEFAULT << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout<< RED << "No Materia to use in "<< idx << " slot." << DEFAULT << std::endl;
		return;
	}
	std::cout << this->_name << " ";
	this->_inventory[idx]->use(target);
}