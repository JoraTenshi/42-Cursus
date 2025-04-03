/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:00:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:15:23 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
	const AAnimal		*cat = new Cat();
	const AAnimal		*dog = new Dog();
	const WrongAnimal	*wronganimal = new WrongAnimal();
	const WrongAnimal	*wrongcat = new WrongCat();

	cat->makeSound();
	dog->makeSound();
	wronganimal->makeSound();
	wrongcat->makeSound();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << wrongcat->getType() << std::endl;

	delete	cat;
	delete	dog;
	delete	wronganimal;
	delete	wrongcat;
	return (0);
}