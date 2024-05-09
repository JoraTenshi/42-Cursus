/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:37:03 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 18:54:27 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft/libft.h"
#include <signal.h>

void	ft_bit_get(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	context = NULL;
	if (!info)
		return ;
	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_bit_get;
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
