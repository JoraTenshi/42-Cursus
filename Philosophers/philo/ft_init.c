/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:27:54 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/01 12:20:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_data(t_data	*data, char **argv)
{
	data->start_time = ft_get_time();
	data->philo_n = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eep = ft_atoi(argv[3]);
	data->t_to_nom = ft_atoi(argv[4]);
	if (argv[5])
		data->must_nom = ft_atoi(argv[5]);
	else
		data->must_nom = 0;
	data->still_breathing = 1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_n);
	if (!data->forks)
		return (ft_errors(ERROR_FORK_ARRAY, data));
	if (pthread_mutex_init(&data->write, NULL))
		return (ft_errors(ERROR_WRITE, data));
	if (pthread_mutex_init(&data->check, NULL))
		return (ft_errors(ERROR_CHECK, data));
}

static void	ft_create_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (ft_errors(ERROR_FORK, data));
		i++;
	}
	i = 0;
	while (i < data->philo_n)
	{
		data->philosophers[i]->rfork = &data->forks[i];
		if (i == 0)
			data->philosophers[i]->lfork = &data->forks[data->philo_n - 1];
		else
			data->philosophers[i]->lfork = &data->forks[i - 1];
		i++;
	}
}

void	ft_create_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philosophers = malloc(sizeof(t_philo) * data->philo_n);
	if (!data->philosophers)
		return (ft_errors(ERROR_PHILO, data));
	while (i < data->philo_n)
	{
		data->philosophers[i] = malloc (sizeof(t_philo));
		if (!data->philosophers[i])
			ft_errors(ERROR_PHILO, data);
		data->philosophers[i]->times_nomd = 0;
		data->philosophers[i]->id = i + 1;
		data->philosophers[i]->last_nom = ft_current_time(data);
		data->philosophers[i]->data = data;
		if (pthread_mutex_init(&data->philosophers[i]->lock, NULL))
			return (ft_errors(ERROR_PHILO, data));
		i++;
	}
	ft_create_forks(data);
}

void	ft_philo_initializer(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		if (pthread_create(&data->philosophers[i]->thread, NULL,
				&ft_routine, data->philosophers[i]))
			return (ft_errors(ERROR_PHILO, data));
		i++;
		usleep(100);
	}
}
