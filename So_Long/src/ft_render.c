/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:19 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/04 17:31:33 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(data->mlx, texture);
	if (!image)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, image, j * 64, i * 64) == -1)
		return (EXIT_FAILURE);
	if (texture == data->textures->collectible)
		return (ft_collectible_array(data, image));
	return (0);
}

void	ft_textures(t_textures *textures)
{
	textures->collectible = mlx_load_png("textures/Tiles/Llave.png");
	textures->exit_closed = mlx_load_png("textures/Tiles/PuertaCerrada.png");
	textures->exit_open = mlx_load_png("textures/Tiles/PuertaAbierta.png");
	textures->floor = mlx_load_png("textures/Tiles/Suelo1.png");
	textures->wall = mlx_load_png("textures/Tiles/Pared2.png");
	textures->player = mlx_load_png("textures/Wizard/Down.png");
	ft_check_textures(textures);
}

void	ft_free_textures(t_textures *textures)
{
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->exit_open);
	mlx_delete_texture(textures->exit_closed);
	mlx_delete_texture(textures->player);
}

//ft_print_data(data);

int	ft_render_player(t_data *data)
{
	ft_start_pos(data);
	if (!data->textures->player)
		return (EXIT_FAILURE);
	data->player = mlx_texture_to_image(data->mlx, data->textures->player);
	if (!data->player)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->player,
			data->x * 64, data->y * 64) < 0)
		return (EXIT_FAILURE);
	data->player->instances[0].enabled = 1;
	return (0);
}

int	ft_render(t_data *data)
{
	t_textures	textures;

	ft_textures(&textures);
	data->textures = &textures;
	ft_fill_map(data);
	ft_render_player(data);
	ft_free_textures(data->textures);
	return (0);
}
