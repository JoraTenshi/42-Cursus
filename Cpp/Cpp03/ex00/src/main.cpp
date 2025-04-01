/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:14:43 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Claptrap.hpp"

int main(void)
{
	Claptrap claptrap("Handsome Jack");
	Claptrap claptrap2(claptrap);
	Claptrap claptrap3;

	claptrap3 = claptrap;
	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
	claptrap.attack("enemy");
	claptrap.beRepaired(3);
	return (0);
}