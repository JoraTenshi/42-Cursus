/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:25 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/12 12:43:02 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	ft_void(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = ft_init(argc, argv);
		if (!ft_errors(&data) && !ft_check_sorted(data.stack_a))
		{
			
		}
		else
			return (1);
	}
	return (0);
}
