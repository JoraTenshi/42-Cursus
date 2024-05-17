/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:20 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/17 10:55:40 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		if (ft_check_map(argv[1]))
		{
			fd = open (argv[1], O_RDONLY);
			if (!fd)
				return (ft_printf("Map error, try again\n"), -1);
		}
		else
			ft_printf("Provide a .ber map\n");
	}
	else if (argc > 2)
		ft_printf("Provide only one map\n");
	else
		ft_printf("Provide a functioning map\n")
}
