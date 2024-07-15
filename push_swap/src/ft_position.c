/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:30:18 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/15 12:47:24 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_set_pos(t_stack *stack)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux->current_pos = i;
		i++;
		aux = aux->next;
	}
}

static	int	ft_get_target(t_stack *stack, int index_b, int index_t, int target)
{
	
}

void	ft_target_pos(t_data *data)
{
	int		target;
	t_stack	*aux;

	aux = data->stack_b;
	ft_set_pos(data->stack_a);
	ft_set_pos(data->stack_b);
	target = 0;
	while (aux)
	{
		target = ft_get_target(data->stack_a, aux->index, INT_MAX, target);
		aux->target_pos = target;
		aux = aux->next;
	}
}
