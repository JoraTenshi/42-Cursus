/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:07:09 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/11 12:30:34 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*ft_lstlast_cmd(t_cmd *lst)
{
	t_cmd	*aux;

	if (lst == NULL)
		return (NULL);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

t_env	*ft_lstlast_tenv(t_env *lst)
{
	t_env	*aux;

	if (lst == NULL)
		return (NULL);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

void	ft_lstadd_back_tenv(t_env **lst, t_env	*new)
{
	t_env	*aux;

	if (*lst == NULL)
		*lst = new;
	else
	{
		aux = ft_lstlast_tenv(*lst);
		aux->next = new;
	}
}

t_env	*ft_lstnew_tenv(char *name, char *value)
{
	t_env	*newlist;

	newlist = malloc(sizeof(t_env));
	if (newlist == NULL)
		return (NULL);
	newlist->name = name;
	newlist->value = value;
	newlist->next = NULL;
	return (newlist);
}

t_env	*ft_lst_env(char **envp, t_env *lst)
{
	int		i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		lst = ft_add_to_env(envp[i], lst);
		i++;
	}
	lst = ft_add_to_env("OLDPWD", lst);
	return (lst);
}
