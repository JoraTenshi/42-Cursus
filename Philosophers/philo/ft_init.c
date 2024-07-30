/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:27:54 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/30 13:05:28 by jcallejo         ###   ########.fr       */
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
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 0;
	data->are_alive = 1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_n);
	if (!data->forks)
		return (ft_errors(ERROR_FORK_ARRAY, data));
	if (pthread_mutex_init(&data->write, NULL))
		return (ft_errors(ERROR_WRITE, data));
	if (pthread_mutex_init(&data->check, NULL))
		return (ft_errors(ERROR_CHECK, data));
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
		data->philosophers[i]->philo_id = i + 1;
		data->philosophers[i]->last_nom = ft_current_time(data);
		data->philosophers[i]->data = data;
		if (pthread_mutex_init(&data->philosophers[i]->lock, NULL))
			return (ft_errors(ERROR_PHILO, data));
		i++;
	}
	ft_create_forks(); //hacerla encima
}
