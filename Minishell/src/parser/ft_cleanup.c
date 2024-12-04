/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:04:12 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 10:34:53 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_clean_cmd(t_data *data)
{
	t_cmd	*aux;
	t_redir	*raux;

	while (data->cmd)
	{
		aux = data->cmd;
		data->cmd = data->cmd->next;
		free(aux->path);
		ft_cl_ar(aux->argv);
		while (aux->redir)
		{
			raux = aux->redir;
			aux->redir = aux->redir->next;
			free(raux->file);
			free(raux);
		}
		free(aux);
	}
	if (ft_get_flag() == 3)
		data->error = 130;
	else if (ft_get_flag() == 4)
		data->error = 131;
}

void	ft_cl_ar(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
