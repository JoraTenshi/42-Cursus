/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:22:08 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/31 12:06:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	nom(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->lfork);
	ft_print_routine(philo, STATUS_TAKE_FORK);
	pthread_mutex_lock(philo->rfork);
	ft_print_routine(philo, STATUS_TAKE_FORK);
	pthread_mutex_lock(&philo->lock);
	philo->last_nom = ft_current_time(philo->data);
	pthread_mutex_unlock(&philo->lock);
	ft_print_routine(philo, STATUS_NOM);
	time = ft_current_time(philo->data) + philo->data->t_to_nom;
	while (ft_current_time(philo->data) <= time)
	{
		if (!ft_are_still_breathing(philo->data))
			break ;
		usleep(1);
	}
	pthread_mutex_lock(&philo->lock);
	philo->times_nomd++;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

static void	eep(t_philo *philo)
{
	long	wakey;

	if (philo->data->t_to_eep == 0)
		return ;
	ft_print_routine(philo, STATUS_EEP);
	wakey = ft_current_time(philo->data) + philo->data->t_to_eep;
	while (ft_current_time(philo->data) < wakey)
	{
		if (!ft_are_still_breathing(philo->data))
			break ;
		usleep(1);
	}
}

static void	tink(t_philo *philo)
{
	long	tink_time;

	pthread_mutex_lock(&philo->lock);
	tink_time = philo->data->t_to_die - ft_current_time(philo->data)
		- philo->last_nom - philo->data->t_to_nom;
	pthread_mutex_unlock(&philo->lock);
	if (tink_time <= 0)
		tink_time = 0;
	ft_print_routine(philo, STATUS_TINK);
	while (ft_current_time(philo->data) < tink_time)
	{
		if (!ft_are_still_breathing(philo->data))
			break ;
		usleep(1);
	}
}

void	ft_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->t_to_die == 0)
		return (NULL);
	while (ft_are_still_breathing(philo->data))
	{
		nom(philo);
		eep(philo);
		tink(philo);
	}
	return (NULL);
}
