/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:16:46 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/12 12:37:39 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_numbers(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_range(char **split)
{
	int		i;
	long	n;

	i = 0;
	while (split[i])
	{
		n = ft_atol(split[i]);
		if (n > INT_MAX && n < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_check_array(int *n, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (n[i] == n[j])
				count++;
			j++;
		}
		if (count != 1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_duplicates(t_stack *stack)
{
	int		i;
	int		size;
	int		duplicate;
	int		*n;
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		i = 0;
		size = ft_stack_size(stack);
		n = (int *) malloc(sizeof(int *) * size);
		if (!n)
			return (0);
		while (aux)
		{
			n[i] = aux->value;
			aux = aux->next;
			i++;
		}
		duplicate = ft_check_array(n, size);
		return (free(n), duplicate);
	}
	return (0);
}

int	ft_errors(t_data *data)
{
	if (!data->stack_a)
		return (1);
	if (ft_check_duplicates(data->stack_a))
	{
		ft_clean_stack(data->stack_a);
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
