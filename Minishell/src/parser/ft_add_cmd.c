/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:47:36 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 10:32:46 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_redir	*new_redir(int type, char *file)
{
	t_redir	*redir;

	redir = 0;
	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = file;
	redir->next = NULL;
	return (redir);
}

static t_redir	*add_back(t_redir *redir, t_redir *node)
{
	t_redir	*aux;

	if (!redir)
		redir = node;
	else
	{
		aux = redir;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
	return (redir);
}

static t_redir	*add_redir(char **argv)
{
	t_redir	*redirs;
	char	*aux;

	redirs = NULL;
	while (*argv)
	{
		aux = ft_custom_strtrim(*argv, " ");
		if (ft_strnstr(aux, ">>", 2))
			redirs = add_back(redirs, new_redir(OUTPUT_APPEND,
						ft_custom_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, "<<", 2))
			redirs = add_back(redirs, new_redir(HEREDOC,
						ft_custom_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, "<", 1))
			redirs = add_back(redirs, new_redir(INPUT_REDIRECT,
						ft_custom_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, ">", 1))
			redirs = add_back(redirs, new_redir(OUTPUT_REDIRECT,
						ft_custom_strtrim(argv[1], " ")));
		argv++;
		free(aux);
	}
	return (redirs);
}

static char	**get_argv(char **argv)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	j = 0;
	while (argv[i] && ft_strncmp(argv[i], "<<", 2)
		&& ft_strncmp(argv[i], ">>", 2) && ft_strncmp(argv[i], "<", 1)
		&& ft_strncmp(argv[i], ">", 1))
		i++;
	aux = malloc(sizeof(char **) * (i + 1));
	if (!aux)
		return (NULL);
	j = 0;
	while (j < i)
	{
		aux[j] = ft_custom_strtrim(argv[j], " ");
		j++;
	}
	aux[i] = 0;
	return (aux);
}

void	ft_add_cmd(t_data *data, t_cmd *cmd, char **argv)
{
	if (!cmd)
		return ;
	if (cmd->argv != NULL)
	{
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_new_cmd();
		cmd = cmd->next;
	}
	cmd->data = data;
	cmd->argv = get_argv(argv);
	cmd->path = ft_custom_strtrim(argv[0], " ");
	cmd->redir = add_redir(argv);
}
