/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:54:35 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 12:16:16 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Diamondtrap.hpp"

int main(void)
{
	DiamondTrap diamond("Stallion");
	DiamondTrap diamond2("Normal Horse");

	diamond.attack("Normal Horse");
	diamond2.takeDamage(30);
	diamond2.beRepaired(20);
	diamond2.guardGate();
	diamond2.highFivesGuys();
	diamond.whoAmI();

	return (0);
}