/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:51:01 by aarenas-          #+#    #+#             */
/*   Updated: 2024/11/15 15:41:16 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_tenv_lstsize(t_env *lst)
{
	t_env	*aux;
	int		i;

	aux = lst;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

static t_env	*ft_swap(t_env **lst)
{
	t_env	*aux;

	if (!lst || ft_tenv_lstsize(*lst) < 2)
		return (NULL);
	aux = (*lst)->next;
	(*lst)->next = aux->next;
	aux->next = (*lst);
	(*lst) = aux;
	aux = NULL;
	return (*lst);
}

static void	ft_swap_next(t_env **lst)
{
	t_env	*aux;

	if (!lst || ft_tenv_lstsize(*lst) < 1)
		return ;
	aux = (*lst)->next->next;
	(*lst)->next->next = aux->next;
	aux->next = (*lst)->next;
	(*lst)->next = aux;
	aux = NULL;
}

static int	ft_check_sort(t_env *lst)
{
	t_env	*aux;

	aux = lst;
	while (aux->next)
	{
		if (ft_strncmp(aux->name, aux->next->name, 1) > 0)
			return (1);
		aux = aux->next;
	}
	return (0);
}

t_env	*ft_sort(t_env *lst)
{
	t_env	*aux;
	int		i;

	while (ft_check_sort(lst))
	{
		i = 0;
		aux = lst;
		while (aux->next)
		{
			if (i == 0 && aux->next
				&& ft_strncmp(aux->name, aux->next->name, ft_strlen(aux->name))
				> 0)
				lst = ft_swap(&aux);
			else if (aux->next->next
				&& ft_strncmp(aux->next->name, aux->next->next->name,
					ft_strlen(aux->next->name)) > 0)
			{
				ft_swap_next(&aux);
			}
			if (i != 0)
				aux = aux->next;
			i++;
		}
	}
	return (lst);
}

/* t_env	*aux2 = lst;

for (int i = 0; i < ft_tenv_lstsize(lst); i++)
{
	printf("i: %d: %s=%s\n", i, aux2->name, aux2->value);
	printf("\n");
	if (aux2->next)
		aux2 = aux2->next;
} */