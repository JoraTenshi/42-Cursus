/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:32:13 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/31 11:45:54 by jcallejo         ###   ########.fr       */
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
	pthread_mutex_unlock(&philo->data->check);
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
	pthread_mutex_unlock(&philo->data->write);
}
