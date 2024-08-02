/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:45:41 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/02 11:20:45 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_thread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		pthread_join(data->philosophers[i]->thread, NULL);
		i++;
	}
}

static void	ft_free_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		pthread_mutex_destroy(&data->philosophers[i]->lock);
		free (data->philosophers[i++]);
	}
	free (data->philosophers);
}

static void	ft_destroy_data_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
		pthread_mutex_destroy(&data->forks[i++]);
	free (data->forks);
	pthread_mutex_destroy(&data->check);
	pthread_mutex_destroy(&data->write);
}

void	ft_clean(t_data *data)
{
	ft_thread_join(data);
	ft_free_philos(data);
	ft_destroy_data_mutex(data);
}
