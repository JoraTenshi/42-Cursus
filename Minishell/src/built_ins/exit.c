/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:08:08 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/25 15:00:09 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_free_env(t_env *env)
{
	while (env->next)
		ft_delete_node(env);
	if (env->name)
		free(env->name);
	if (env->value)
		free(env->value);
	env->name = NULL;
	env->value = NULL;
	free(env);
}

static void	ft_write_exit_error(int error)
{
	if (error == 1)
		ft_putstr("minishell: exit: too many arguments\n");
	else if (error == 2)
		ft_putstr("minishell: exit: numeric argument required\n");
}

void	ft_exit(char **argv, t_data *data)
{
	int	error;

	error = 0;
	while (error % 256)
		error /= 256;
	if (!argv && data)
		error = data->error;
	else if (argv[0] && ft_isdigit(*argv[0]) == 0)
		ft_write_exit_error(2);
	else if (argv[0] && ft_isdigit(*argv[0]) == 1 && argv[1])
		ft_write_exit_error(1);
	else if (argv[0] && ft_isdigit(*argv[0]) == 1)
		error = ft_atoi(argv[0]);
	ft_free_env(data->env);
	ft_free_env(data->env_export);
	ft_clean_cmd(data);
	exit(error);
}
