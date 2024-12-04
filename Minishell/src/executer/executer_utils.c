/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:52:49 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/28 18:30:27 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_wait(int *error)
{
	int	status;
	int	out_status;

	out_status = 0;
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		out_status = WEXITSTATUS(status);
	else if (WIFEXITED(status) && WIFSIGNALED(status) != 0)
		out_status = WTERMSIG(status);
	else
		out_status = 0;
	*error = out_status;
}

void	ft_check_redirs(t_cmd *cmd)
{
	t_redir	*aux;

	if (!cmd->redir)
		return ;
	aux = cmd->redir;
	while (aux)
	{
		if (aux->type == INPUT_REDIRECT
			|| aux->type == HEREDOC)
			ft_in_redir(cmd->data, aux);
		else if (aux->type == OUTPUT_REDIRECT
			|| aux->type == OUTPUT_APPEND)
			ft_out_redir(aux);
		aux = aux->next;
	}
}

void	ft_puterrorstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	ft_free(char **str)
{
	char	**ptr;

	if (!str)
		return ;
	ptr = str;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}

void	ft_freeanderror(t_data *lst)
{
	free(lst);
	perror("Error");
}
