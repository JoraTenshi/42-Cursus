/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:38:37 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 12:42:08 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	shell_lvl(t_data *data)
{
	char	*lvl;
	char	*str;
	char	*aux;
	int		i;

	lvl = ft_get_env(data, "SHLVL")->value;
	i = ft_atoi(lvl) + 1;
	lvl = ft_itoa(i);
	aux = ft_strdup("SHLVL=");
	str = ft_strjoin(aux, lvl);
	ft_export(str, data);
	free(lvl);
	free(aux);
	free(str);
}

static void	update_name(t_data *data)
{
	char	*name;
	char	*str;
	char	*aux;

	aux = ft_strdup("SHELL=");
	name = ft_strdup("minishell");
	str = ft_strjoin(aux, name);
	ft_export(str, data);
	free(str);
	free(name);
	free(aux);
}

int	ft_init(t_data *data, char **envp)
{
	data->env = NULL;
	data->env_export = NULL;
	data->cmd = NULL;
	data->input = 0;
	data->heredoc = 0;
	data->error = 0;
	data->envp = 0;
	data->atmp = 0;
	data->origin_envp = envp;
	ft_init_signals();
	data->env = ft_lst_env(data->origin_envp, data->env);
	data->env_export = ft_lst_env(data->origin_envp, data->env_export);
	shell_lvl(data);
	update_name(data);
	return (1);
}
