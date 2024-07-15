/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:36:50 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/15 12:05:20 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_three_sort(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = data->stack_a->value;
	y = data->stack_a->next->value;
	z = data->stack_a->next->next->value;
	if (x > y && x < z && y < z)
		sa(data);
	else if (x > y && x > y && y < z)
		ra(data);
	else if (x < y && x > z && y > z)
		rra(data);
	else if (x > y && x > z && y > z)
	{
		sa(data);
		rra(data);
	}
	else
	{
		sa(data);
		ra(data);
	}
}

static void	ft_push_stack_to_b(t_data *data)
{
	
}

static void	ft_sort_stack(t_data *data)
{
	t_stack	node;
	int		size;

	ft_push_stack_to_b(data);
	if (!ft_check_sorted(data->stack_a))
		ft_three_sort(data);
	while (data->stack_b)
	{
		
	}
}

void	ft_sort(t_data *data)
{
	int	size;

	size = ft_stack_size(data->stack_a);
	if (size == 1)
		return ;
	if (size == 2 && !ft_check_sorted(data->stack_a))
		sa(data);
	if (size == 3 && !ft_check_sorted(data->stack_a))
		ft_three_sort(data);
	else
		ft_sort_stack(data);
}
