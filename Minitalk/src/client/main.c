/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:21:59 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:41 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft/libft.h"

void	bit_send(int pid, char c)
{
	
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
			byte_send(pid, *argv[2]++);
	}
	else
		ft_printf("You didn't introduce a valid argument");
	return (0);
}
