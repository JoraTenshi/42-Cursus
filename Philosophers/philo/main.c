/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:30:44 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/01 12:45:09 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_loop(t_data *data)
{
	while (1)
	{
		if (ft_check_philos(data))
			break ;
	}
}

int	main(int argc, char const **argv)
{
	t_data	data;

	if (ft_check(argc, argv))
	{
		ft_init_data(&data, argv);
		ft_create_philo(&data);
		if (ft_are_still_breathing(&data))
		{
			ft_philo_initializer(&data);
			ft_loop(&data);
		}
		usleep(100);
	}
	else
		printf("Usage: ./philo number_of_philosophers time_to_die \
		time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n");
	return (0);
}
