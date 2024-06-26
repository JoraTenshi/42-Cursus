/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:21:59 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 18:54:03 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft/libft.h"
#include <signal.h>

void	ft_bit_send(int pid, char c)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if (c >> (8 - i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
			ft_bit_send(pid, *argv[2]++);
		ft_bit_send(pid, 0);
	}
	else
		ft_printf("You didn't introduce a valid argument\n");
	return (0);
}
