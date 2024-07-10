/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:56 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/10 11:43:51 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_data *data)
{
	t_stack	*penul;

	penul = data->stack_a;
	while (penul->next->next)
		penul = penul->next;
	penul->next->next = data->stack_a;
	data->stack_a = penul->next;
	penul->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	t_stack	*penul;

	penul = data->stack_b;
	while (penul->next->next)
		penul = penul->next;
	penul->next->next = data->stack_b;
	data->stack_b = penul->next;
	penul->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	t_stack	*penul;

	penul = data->stack_a;
	while (penul->next->next)
		penul = penul->next;
	penul->next->next = data->stack_a;
	data->stack_a = penul->next;
	penul->next = NULL;
	penul = data->stack_b;
	while (penul->next->next)
		penul = penul->next;
	penul->next->next = data->stack_b;
	data->stack_b = penul->next;
	penul->next = NULL;
	write(1, "rrr\n", 4);
}
