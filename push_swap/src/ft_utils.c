/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:44:15 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/17 11:30:57 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_check_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next && aux->next->value > aux->value)
		aux = aux->next;
	if (aux->next == NULL)
		return (1);
	return (0);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
