/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:32:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/11 12:08:42 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::Cat(Brain &brain): AAnimal("Cat")
{
	std::cout << "Cat constructor with Brain called" << std::endl;
	_brain = &brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = src._brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << PURPLE << "Cat says: Meow" << DEFAULT << std::endl;
}