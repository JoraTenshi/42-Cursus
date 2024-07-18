/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:21:41 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/18 11:03:58 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack	*ft_new_stack(char *value)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = ft_atoi(value);
	node->cost_a = 0;
	node->cost_b = 0;
	node->current_pos = -1;
	node->index = -1;
	node->target_pos = -1;
	node->next = NULL;
	return (node);
}

static t_stack	*fill_stack(char **split)
{
	int			i;
	t_stack		*start;
	t_stack		*current;

	i = 0;
	start = NULL;
	while (split[i])
	{
		if (!start)
		{
			start = ft_new_stack(split[i]);
			current = start;
		}
		else
		{
			current->next = ft_new_stack(split[i]);
			current = current->next;
		}
		i++;
	}
	return (start);
}

t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**split;

	split = NULL;
	stack_a = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!ft_check_numbers(split) && !ft_check_range(split))
			stack_a = fill_stack(split);
		else
			write(2, "Error\n", 7);
		ft_clean_array(split);
	}
	else
	{
		argv++;
		if (!ft_check_numbers(argv) && !ft_check_range(argv))
			stack_a = fill_stack(argv);
		else
			write(2, "Error\n", 7);
	}
	return (stack_a);
}

void	ft_index(t_data *data)
{
	int		size;
	t_stack	*aux;
	t_stack	*highest;

	size = ft_stack_size(data->stack_a);
	while (size > 0)
	{
		aux = data->stack_a;
		highest = NULL;
		while (aux)
		{
			if (aux->index == -1)
				if (!highest || aux->value > highest->value)
					highest = aux;
			aux = aux->next;
		}
		if (highest)
			highest->index = size;
		size--;
	}
}
