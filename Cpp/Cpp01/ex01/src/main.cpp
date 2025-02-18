/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:20:23 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/18 11:54:18 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
	Zombie *horde;

	horde = zombieHorde(25, "CarlosDuty");
	for (int i = 0; i < 25; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}