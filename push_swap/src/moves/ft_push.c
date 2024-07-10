/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:32 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/10 11:29:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa(t_data *data)
{
	t_stack	*aux;

	if (data->stack_b)
	{
		if (!data->stack_a)
		{
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->next = NULL;
		}
		else
		{
			aux = data->stack_a;
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->next = aux;
		}
	}
	write (1, "pa\n", 3);
}

void	pb(t_data *data)
{
	t_stack	*aux;

	if (data->stack_a)
	{
		if (!data->stack_b)
		{
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			data->stack_b->next = NULL;
		}
		else
		{
			aux = data->stack_b;
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			data->stack_b->next = aux;
		}
	}
	write (1, "pb\n", 3);
}
