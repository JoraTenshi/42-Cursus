/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:25 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/18 13:14:41 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	ft_void(void)
// {
// 	system("leaks -q push_swap");
// }

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (0);
	return (1);
}

static void	ft_execute(char *operation, t_data *data)
{
	if (ft_strcmp(operation, "sa\n"))
		sa(data);
	else if (ft_strcmp(operation, "sb\n"))
		sb(data);
	else if (ft_strcmp(operation, "ss\n"))
		ss(data);
	else if (ft_strcmp(operation, "pa\n"))
		pa(data);
	else if (ft_strcmp(operation, "pb\n"))
		pb(data);
	else if (ft_strcmp(operation, "ra\n"))
		ra(data);
	else if (ft_strcmp(operation, "rb\n"))
		rb(data);
	else if (ft_strcmp(operation, "rr\n"))
		rr(data);
	else if (ft_strcmp(operation, "rra\n"))
		rra(data);
	else if (ft_strcmp(operation, "rrb\n"))
		rrb(data);
	else if (ft_strcmp(operation, "rrr\n"))
		rrr(data);
}

static void	ft_checker(t_data *data)
{
	char	*aux;

	aux = get_next_line(0);
	while (aux)
	{
		ft_execute(aux, data);
		free(aux);
		aux = get_next_line(0);
	}
	if (ft_check_sorted(data->stack_a) && !data->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = ft_init(argc, argv);
		data.stack_b = NULL;
		if (!ft_errors(&data))
		{
			ft_index(&data);
			ft_checker(&data);
			ft_clean_stack(data.stack_a);
			ft_clean_stack(data.stack_b);
		}
		else
			return (1);
	}
	return (0);
}
