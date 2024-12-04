/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:42 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/27 19:13:05 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_check_cd_unset(t_cmd *cmd, int *builtin_done)
{
	int	i;

	i = 1;
	if (ft_strncmp(cmd->path, "unset\0", 6) == 0)
	{
		if (cmd->argv)
		{
			while (cmd->argv[i])
			{
				ft_unset(&cmd->data->env, cmd->argv[i]);
				ft_unset(&cmd->data->env_export, cmd->argv[i]);
				i++;
			}
			cmd->data->error = 0;
		}
	}
	else if (ft_strncmp(cmd->path, "cd\0", 3) == 0)
	{
		if (cmd->argv[1])
			ft_cd(cmd->data, &cmd->argv[1]);
		else
			ft_cd(cmd->data, NULL);
	}
	else
		*builtin_done = 1;
}

void	ft_check_built_ins(t_cmd *cmd, int *builtin_done)
{
	int	i;

	i = 1;
	*builtin_done = 0;
	if (ft_strncmp(cmd->path, "env\0", 4) == 0)
		ft_env(cmd->data->env, &cmd->data->error);
	else if (ft_strncmp(cmd->path, "exit\0", 5) == 0)
		ft_exit(&cmd->argv[1], cmd->data);
	else if (ft_strncmp(cmd->path, "echo\0", 5) == 0)
		ft_echo(&cmd->argv[1], &cmd->data->error);
	else if (ft_strncmp(cmd->path, "pwd\0", 4) == 0)
		ft_pwd(cmd->data);
	else if (ft_strncmp(cmd->path, "export\0", 7) == 0)
	{
		if (cmd->argv[i])
			while (cmd->argv[i])
				ft_export(cmd->argv[i++], cmd->data);
		else
			ft_export(NULL, cmd->data);
	}
	else
		ft_check_cd_unset(cmd, builtin_done);
}

	//ft_free_data(data); estoy hay que ponerlo cuando termine el programa