/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:30:35 by jcallejo          #+#    #+#             */
/*   Updated: 2025/02/27 13:36:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	load_torch(t_data *data, int i)
{
	char			*aux;
	char			*path;
	mlx_texture_t	*texture;

	path = ft_itoa(i);
	aux = ft_strjoin(path, ".png");
	free(path);
	path = ft_strjoin("./textures/torch/", aux);
	free(aux);
	texture = mlx_load_png(path);
	data->torch.torch[i] = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, data->torch.torch[i], data->width / 2 + 300,
		data->height / 2);
	data->torch.torch[i]->enabled = 0;
	mlx_delete_texture(texture);
	free(path);
}

void	ft_load_animation(t_data *data)
{
	int	i;

	i = 0;
	data->torch.torch = malloc(sizeof(mlx_image_t) * 10);
	if (!data->torch.torch)
		ft_errors(data, ERR_SYS, NULL);
	data->torch.frame = 0;
	while (i < 10)
		load_torch(data, i++);
}
