/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:38:57 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:08:52 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(Brain &brain): AAnimal("Dog")
{
	std::cout << "Dog constructor with Brain called" << std::endl;
	_brain = &brain;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = src._brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << RED << "Dog says: Woof" << DEFAULT << std::endl;
}