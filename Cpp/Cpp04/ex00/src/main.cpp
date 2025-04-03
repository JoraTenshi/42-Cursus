/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:00:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:46:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	const Animal		*animal = new Animal();
	const Animal		*cat = new Cat();
	const Animal		*dog = new Dog();
	const WrongAnimal	*wronganimal = new WrongAnimal();
	const WrongAnimal	*wrongcat = new WrongCat();

	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wronganimal->makeSound();
	wrongcat->makeSound();

	std::cout	<< cat->getType() << std::endl;
	std::cout	<< dog->getType() << std::endl;
	std::cout	<< wrongcat->getType() << std::endl;

	delete	animal;
	delete	cat;
	delete	dog;
	delete	wronganimal;
	delete	wrongcat;
	return (0);
}