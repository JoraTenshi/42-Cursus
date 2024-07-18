/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:36:50 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/18 11:35:14 by jcallejo         ###   ########.fr       */
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
	int	i;
	int	stack_size;
	int	pushed;

	i = 0;
	pushed = 0;
	stack_size = ft_stack_size(data->stack_a);
	while (pushed < stack_size / 2 && (stack_size / 2) > 3 && i < stack_size)
	{
		if (data->stack_a->index <= (stack_size / 2))
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(data);
		pushed++;
	}
}

static	void	ft_what_move(t_data *data, t_stack *node)
{
	if (node->cost_a == 0 && node->cost_b == 0)
		pa(data);
	else if (node->cost_a < 0 && node->cost_b < 0)
		rrr(data);
	else if (node->cost_a > 0 && node->cost_b > 0)
		rr (data);
	else if (node->cost_a < 0)
		rra(data);
	else if (node->cost_a > 0)
		ra(data);
	else if (node->cost_b < 0)
		rrb(data);
	else if (node->cost_b > 0)
		rb(data);
}

static void	ft_sort_stack(t_data *data)
{
	t_stack	*node;
	int		size;

	ft_push_stack_to_b(data);
	if (!ft_check_sorted(data->stack_a))
		ft_three_sort(data);
	while (data->stack_b)
	{
		ft_target_pos(data);
		ft_calculate_cost(data);
		node = ft_cheaper(data);
		ft_what_move(data, node);
	}
	size = ft_stack_size(data->stack_a);
	while (!ft_check_sorted(data->stack_a))
	{
		if (data->stack_a->index > size / 2)
			ra(data);
		else
			rra(data);
	}
}

void	ft_sort(t_data *data)
{
	int	size;

	size = ft_stack_size(data->stack_a);
	if (size == 1)
		return ;
	else if (size == 2 && !ft_check_sorted(data->stack_a))
		sa(data);
	else if (size == 3 && !ft_check_sorted(data->stack_a))
		ft_three_sort(data);
	else
		ft_sort_stack(data);
}
