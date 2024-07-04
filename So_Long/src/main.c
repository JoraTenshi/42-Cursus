/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:20 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/02 13:22:15 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	ft_void(void)
// {
// 	system("leaks -q so_long");
//}

int	ft_check_ber(char	*argv)
{
	char	*aux;

	aux = argv;
	while (*aux)
		aux++;
	while (argv < aux)
	{
		if (*aux == '.')
			if (*aux + 1 && *aux + 2 && *aux + 3)
				if (aux[1] == 'b' && aux[2] == 'e' && aux[3] == 'r' && !aux[4])
					return (1);
		aux--;
	}
	return (0);
}

//atexit(ft_void); Meter al main

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		if (ft_check_ber(argv[1]))
		{
			fd = open (argv[1], O_RDONLY);
			if (!fd)
				return (ft_printf("Map error, try again\n"), -1);
			close(fd);
			return (ft_map(argv[1]));
		}
		else
			ft_printf("Provide a .ber map\n");
	}
	else if (argc > 2)
		ft_printf("Provide only one map\n");
	else
		ft_printf("Provide a functioning map\n");
}
