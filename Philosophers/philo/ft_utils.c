/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:32:13 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/09 11:19:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->check);
	pthread_mutex_unlock(&philo->data->write);
}

void	ft_print_routine(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data->check);
	pthread_mutex_lock(&philo->data->write);
	if (status == STATUS_DIE)
		philo->data->still_breathing = 0;
	if (!philo->data->still_breathing && status != STATUS_DIE)
	{
		free_mutex(philo);
		return ;
	}
	if (status == STATUS_DIE)
		printf(RED"%ld %d died\n"DEFAULT,
			ft_current_time(philo->data), philo->id);
	else if (status == STATUS_NOM)
		printf("%ld %d is eating\n", ft_current_time(philo->data), philo->id);
	else if (status == STATUS_EEP)
		printf("%ld %d is sleeping\n", ft_current_time(philo->data), philo->id);
	else if (status == STATUS_TINK)
		printf("%ld %d is thinking\n", ft_current_time(philo->data), philo->id);
	else if (status == STATUS_TAKE_FORK)
		printf("%ld %d has taken a fork\n",
			ft_current_time(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->check);
	pthread_mutex_unlock(&philo->data->write);
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

int	ft_alive_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (philo->data->t_to_die < ft_current_time(philo->data) - philo->last_nom)
	{
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->data->check);
		philo->data->still_breathing = 0;
		pthread_mutex_unlock(&philo->data->check);
		ft_print_routine(philo, STATUS_DIE);
		return (0);
	}
	pthread_mutex_unlock(&philo->lock);
	return (1);
}

int	ft_check_philos(t_data *data)
{
	int	i;
	int	finish_nomming;

	i = 0;
	finish_nomming = 1;
	while (data->philosophers[i] != NULL)
	{
		if (!ft_alive_check(data->philosophers[i]))
			return (1);
		pthread_mutex_lock(&data->check);
		if (data->must_nom == 0
			|| data->philosophers[i]->times_nomd < data->must_nom)
			finish_nomming = 0;
		pthread_mutex_unlock(&data->check);
		i++;
	}
	if (finish_nomming)
	{
		pthread_mutex_lock(&data->check);
		data->still_breathing = 0;
		pthread_mutex_unlock(&data->check);
	}
	return (finish_nomming);
}
