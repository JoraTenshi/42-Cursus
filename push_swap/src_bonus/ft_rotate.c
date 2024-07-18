/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:54 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/18 13:11:59 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_data *data)
{
	t_stack	*last;

	if (ft_stack_size(data->stack_a) <= 1)
		return ;
	last = ft_last_node(data->stack_a);
	last->next = data->stack_a;
	data->stack_a = data->stack_a->next;
	last->next->next = NULL;
}

void	rb(t_data *data)
{
	t_stack	*last;

	if (ft_stack_size(data->stack_b) <= 1)
		return ;
	last = ft_last_node(data->stack_b);
	last->next = data->stack_b;
	data->stack_b = data->stack_b->next;
	last->next->next = NULL;
}

void	rr(t_data *data)
{
	t_stack	*last;

	if (ft_stack_size(data->stack_a) <= 1 || ft_stack_size(data->stack_b) <= 1)
		return ;
	last = ft_last_node(data->stack_a);
	last->next = data->stack_a;
	data->stack_a = data->stack_a->next;
	last->next->next = NULL;
	last = ft_last_node(data->stack_b);
	last->next = data->stack_b;
	data->stack_b = data->stack_b->next;
	last->next->next = NULL;
}
