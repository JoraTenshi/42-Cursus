/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:52 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/18 13:08:29 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_data *data)
{
	t_stack	*next;

	if (data->stack_a && data->stack_a->next)
	{
		next = data->stack_a->next;
		data->stack_a->next = data->stack_a->next->next;
		next->next = data->stack_a;
		data->stack_a = next;
	}
}

void	sb(t_data *data)
{
	t_stack	*next;

	if (data->stack_b && data->stack_b->next)
	{
		next = data->stack_b->next;
		data->stack_b->next = data->stack_b->next->next;
		next->next = data->stack_b;
		data->stack_b = next;
	}
}

void	ss(t_data *data)
{
	t_stack	*next;

	if (data->stack_a && data->stack_a->next)
	{
		next = data->stack_a->next;
		data->stack_a->next = data->stack_a->next->next;
		next->next = data->stack_a;
		data->stack_a = next;
	}
	if (data->stack_b && data->stack_b->next)
	{
		next = data->stack_b->next;
		data->stack_b->next = data->stack_b->next->next;
		next->next = data->stack_b;
		data->stack_b = next;
	}
}
