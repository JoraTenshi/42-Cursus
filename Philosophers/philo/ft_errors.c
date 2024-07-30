/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/30 12:13:17 by jcallejo         ###   ########.fr       */
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
		printf("Error writing mutex\n");
	if (error_n == ERROR_CHECK)
		printf("Error checking mutex\n");
}
