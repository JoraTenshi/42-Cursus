/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:35:56 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/05 12:50:03 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_init(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->moves = 0;
	data->p_collectibles = 0;
	data->t_collectibles = 0;
	data->player = NULL;
	data->textures = NULL;
	data->collectible_images = NULL;
	data->exit_image = NULL;
	data->end = 0;
}

int	ft_check_characters(char **map, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != '*')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_print_data(t_data *data)
{
	int	i;

	ft_printf("Data:\n  Pos: %d,%d\n  Size: %d*%d\n\n",
		data->x, data->y, data->size_x, data->size_y);
	i = 0;
	while (data->map[i])
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
	ft_printf("\n");
}
