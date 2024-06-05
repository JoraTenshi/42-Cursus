/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:53:06 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/05 12:49:58 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_close(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

void	ft_check_game_status(t_data *data)
{
	if (data->p_collectibles == 0)
	{
		mlx_close_window(data->mlx);
		ft_printf("CONGRATULATIONS, YOU WON!\n");
	}
	else
		ft_printf("The door is not open yet...\n");
}

void	ft_freemap(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	free(data->map);
}

void	ft_terminate(t_data *data)
{
	ft_freemap(data);
	free(data->collectible_images);
	free(data->exit_image);
	mlx_terminate(data->mlx);
}
