/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:49 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/06 11:31:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		harl.complain("");
	return (0);
}
