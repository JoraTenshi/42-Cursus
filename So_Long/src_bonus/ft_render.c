/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:19 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/18 11:55:19 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	textures->playerup = mlx_load_png("textures/Wizard/Up.png");
	textures->playerdown = mlx_load_png("textures/Wizard/Down.png");
	textures->playerleft = mlx_load_png("textures/Wizard/Left.png");
	textures->playerright = mlx_load_png("textures/Wizard/Right.png");
	textures->slimeup = mlx_load_png("textures/Slime/Up.png");
	textures->slimedown = mlx_load_png("textures/Slime/Down.png");
	textures->slimeleft = mlx_load_png("textures/Slime/Left.png");
	textures->slimeright = mlx_load_png("textures/Slime/Right.png");
}

void	ft_free_textures(t_textures *textures)
{
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->exit_open);
	mlx_delete_texture(textures->exit_closed);
	mlx_delete_texture(textures->playerup);
	mlx_delete_texture(textures->playerdown);
	mlx_delete_texture(textures->playerleft);
	mlx_delete_texture(textures->playerright);
	mlx_delete_texture(textures->slimeup);
	mlx_delete_texture(textures->slimedown);
	mlx_delete_texture(textures->slimeleft);
	mlx_delete_texture(textures->slimeright);
}

//ft_print_data(data);

void	ft_render_player(t_data *data, t_anim *player)
{
	ft_start_pos(data);
	if (!data->textures->playerup || !data->textures->playerdown
		|| !data->textures->playerleft || !data->textures->playerright)
		return ;
	player->up = mlx_texture_to_image(data->mlx,
			data->textures->playerup);
	player->down = mlx_texture_to_image(data->mlx,
			data->textures->playerdown);
	player->left = mlx_texture_to_image(data->mlx,
			data->textures->playerleft);
	player->right = mlx_texture_to_image(data->mlx,
			data->textures->playerright);
	if (ft_aux_render_player(data, player) != EXIT_FAILURE)
		return ;
	player->up->instances[0].enabled = 0;
	player->down->instances[0].enabled = 1;
	player->left->instances[0].enabled = 0;
	player->right->instances[0].enabled = 0;
}

int	ft_render(t_data *data)
{
	t_textures	textures;
	t_anim		player;

	ft_textures(&textures);
	data->textures = &textures;
	ft_fill_map(data);
	ft_render_player(data, &player);
	data->player = &player;
	ft_free_textures(data->textures);
	return (0);
}
