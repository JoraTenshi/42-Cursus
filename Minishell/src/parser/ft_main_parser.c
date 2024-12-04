/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:33:13 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 11:53:48 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	parser_if(t_data *data)
{
	if (!ft_isalpha(*data->input) && *data->input != '.' && *data->input != '/'
		&& *data->input != '"' && *data->input != '\'' && *data->input != '|'
		&& *data->input != '$')
		return (0);
	return (1);
}

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->data = NULL;
	cmd->argv = NULL;
	cmd->path = NULL;
	cmd->redir = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*ft_parser(t_data *data)
{
	char	**pipes;
	char	**argv;
	int		i;
	t_cmd	*cmd;

	i = -1;
	if (parser_if(data) == 0)
		return (printf("minishell: parser: bad input\n"), NULL);
	pipes = ft_pipesplit(data->input);
	if (!pipes || !pipes[0][0])
		return (ft_cl_ar(pipes), printf("minishell: syntax error\n"), NULL);
	cmd = ft_new_cmd();
	while (pipes[++i])
	{
		argv = ft_minisplit(data, pipes[i]);
		if (!argv)
			return (ft_cl_ar(pipes), free(cmd),
				printf("minishell: syntax error\n"), NULL);
		ft_parse_env(data, argv);
		ft_dequote(argv);
		ft_add_cmd(data, cmd, argv);
		ft_cl_ar(argv);
		data->cmd = cmd;
	}
	return (ft_cl_ar(pipes), cmd);
}
