/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:19 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/29 11:47:17 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(data->mlx, texture);
}

t_textures	ft_textures(void)
{
	t_textures	textures;

	textures.collectible = mlx_load_png("textures/Tiles/Moneda.png");
	textures.exit_closed = mlx_load_png("textures/Tiles/PuertaCerrada.png");
	textures.exit_open = mlx_load_png("textures/Tiles/PuertaAbierta.png");
	textures.floor = mlx_load_png("textures/Tiles/Suelo1.png");
	textures.wall = mlx_load_png("textures/Tiles/Pared.png");
	textures.player = mlx_load_png("textures/Wizard/tile002.png");
}
