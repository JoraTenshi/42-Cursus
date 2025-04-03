/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:49:20 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 13:53:10 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* noctis = new Character("Noctis Lucis Caelum");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	noctis->equip(tmp);
	tmp = src->createMateria("cure");
	noctis->equip(tmp);

	ICharacter* shtola = new Character("Y'shtola Rhul");

	noctis->use(0, *shtola);
	noctis->use(1, *shtola);

	delete noctis;
	delete shtola;
	delete src;

	return 0;
}