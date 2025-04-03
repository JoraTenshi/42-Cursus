/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:14:43 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 11:38:09 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Claptrap.hpp"
int main(void)
{
	ClapTrap ClapTrap("Handsome Jack");
	
	ClapTrap.attack("enemy");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(3);
	ClapTrap.takeDamage(10);
	ClapTrap.attack("enemy");
	ClapTrap.beRepaired(3);
	return (0);
}