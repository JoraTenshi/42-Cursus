/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/09 11:07:02 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_errors(int error_n)
{
	if (error_n == ERROR_PHILO)
		printf("Error creating philosopher\n");
	if (error_n == ERROR_FORK)
		printf("Error creating fork\n");
	if (error_n == ERROR_FORK_ARRAY)
		printf("Error creating fork array\n");
	if (error_n == ERROR_WRITE)
		printf("Error creating write mutex\n");
	if (error_n == ERROR_CHECK)
		printf("Error creating check mutex\n");
}

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Every argument has to be a number greater than zero\n");
			return (0);
		}
		i++;
	}
	if (argc < 5 || argc > 6)
	{
		printf("Number of arguments must be between 5 and 6\n");
		return (0);
	}
	return (1);
}
