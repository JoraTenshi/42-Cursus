/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:54:35 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 18:17:03 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Scavtrap.hpp"
#include "../inc/Fragtrap.hpp"

int main(void)
{
	Claptrap claptrap("Handsome Jack");
	Scavtrap scavtrap("Krieg");
	Fragtrap fragtrap("Tiny Tina");

	
	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	scavtrap.attack("target");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.attack("target");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.attack("target");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);

	fragtrap.attack("target");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(10);
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(200);
	fragtrap.highFivesGuys();
	
	return (0);
}