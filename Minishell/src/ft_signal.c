/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:51:38 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 17:11:02 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	g_signal_flag = 0;

void	ft_set_flag(int i)
{
	g_signal_flag = i;
}

void	ft_handler_int(int signal)
{
	(void) signal;
	ft_putendl_fd("", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_signal_flag == 0)
		rl_redisplay();
	ft_set_flag(3);
}

void	backslash_control(int signal)
{
	(void) signal;
	if (g_signal_flag == 1)
		ft_putendl_fd("Quit (Core dumped)", 2);
	ft_set_flag(4);
}

int	ft_get_flag(void)
{
	return (g_signal_flag);
}

void	ft_init_signals(void)
{
	signal(SIGINT, ft_handler_int);
	signal(SIGQUIT, SIG_IGN);
}
