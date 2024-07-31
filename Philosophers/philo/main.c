/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:30:44 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/31 11:31:35 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char const **argv)
{
	t_data	data;

	if (ft_check(argc, argv))
	{
		ft_init_data(&data, argv);
		ft_create_philo(&data);
		if (ft_are_still_breathing(&data))
		{
			
		}
	}
	else
		printf("Usage: ./philo number_of_philosophers time_to_die \
		time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n");
	return (0);
}
