/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:00:10 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/15 11:19:33 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
	// Animal	*animals[10];

	// for (int i = 0; i < 10; i++)
	// {
	// 	if (i < 5)
	// 		animals[i] = new Dog();
	// 	else
	// 		animals[i] = new Cat();
	// }

	// for (int i = 0; i < 10; i++)
	// 	animals[i]->makeSound();
	// for (int i = 0; i < 10; i++)
	// 	delete animals[i];

	Cat cat1;
	{
		Cat tmp = cat1;
	}
	
	return (0);
}