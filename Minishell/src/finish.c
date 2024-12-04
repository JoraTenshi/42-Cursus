/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:28:18 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/08 11:54:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_free_tenv(t_env **lst)
{
	t_env	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->name)
			free((*lst)->name);
		if ((*lst)->value)
			free((*lst)->value);
		(*lst)->name = NULL;
		(*lst)->value = NULL;
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}

void	ft_free_data(t_data *data)
{
	ft_free_tenv(&data->env);
	ft_free_tenv(&data->env_export);
}
