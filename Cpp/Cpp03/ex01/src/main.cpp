/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:54:35 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 18:15:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Scavtrap.hpp"

int main(void)
{
	Claptrap claptrap("Handsome Jack");
	Scavtrap scavtrap("Krieg");

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

	return (0);
}