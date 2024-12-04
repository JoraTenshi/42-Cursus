/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:04:51 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 18:37:30 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	ft_void(void)
// {
// 	system("leaks -q minishell");
// }

void	ft_delete_heredoc(void)
{
	int	fd;

	fd = open(".heredoc_tmp", O_RDONLY);
	if (fd > 0)
		unlink(".heredoc_tmp");
}

//atexit(ft_void);

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (!*envp)
		return (printf("minishell: envp: enviroment must not be emty\n"), 1);
	ft_init(&data, envp);
	while (1)
	{
		if (ft_read_string(&data))
		{
			if (*data.input && envp)
			{
				data.cmd = ft_parser(&data);
				if (data.cmd)
				{
					ft_set_flag(1);
					signal(SIGQUIT, backslash_control);
					ft_executer(&data);
					ft_delete_heredoc();
					ft_clean_cmd(&data);
				}
			}
		}
		ft_set_flag(0);
	}
	return ((void)argv, (void)argc, free(data.input), data.error);
}
