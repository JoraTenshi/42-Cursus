/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/31 11:17:55 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_errors(int error_n, t_data *data)
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
			printf("Every argument has to be bigger than zero\n");
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

int	ft_are_still_breathing(t_data *data)
{
	pthread_mutex_lock(&data->check);
	if (data->still_breathing)
	{
		pthread_mutex_unlock(&data->check);
		return (1);
	}
	pthread_mutex_unlock(&data->check);
	return (0);
}
