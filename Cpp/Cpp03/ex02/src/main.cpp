/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:54:35 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 11:40:38 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Scavtrap.hpp"
#include "../inc/Fragtrap.hpp"

int main(void)
{
	ClapTrap ClapTrap("Handsome Jack");
	ScavTrap ScavTrap("Krieg");
	FragTrap FragTrap("Tiny Tina");

	
	ClapTrap.attack("target");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(3);
	ClapTrap.attack("target");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);
	ClapTrap.attack("target");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);

	ScavTrap.attack("target");
	ScavTrap.takeDamage(5);
	ScavTrap.beRepaired(3);
	ScavTrap.attack("target");
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(5);
	ScavTrap.attack("target");
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(5);

	FragTrap.attack("target");
	FragTrap.takeDamage(20);
	FragTrap.beRepaired(10);
	FragTrap.highFivesGuys();
	FragTrap.takeDamage(200);
	FragTrap.highFivesGuys();
	
	return (0);
}