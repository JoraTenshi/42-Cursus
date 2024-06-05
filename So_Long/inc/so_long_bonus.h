/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:58:41 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/05 12:48:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WIDTH 256
# define HEIGHT 256

# include "../Libft/inc/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*player;
}	t_textures;

typedef struct s_data
{
	mlx_t			*mlx;
	char			**map;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				moves;
	int				p_collectibles;
	int				t_collectibles;
	mlx_image_t		*player;
	t_textures		*textures;
	mlx_image_t		**collectible_images;
	mlx_image_t		**exit_image;
	int				end;
	double			time;
	double			atime;
	char			keypressed;
}	t_data;

/**
 * @brief Function to check if the provided map is a rectangle
 * 
 * @param str 
 * @return int 
 */
int		ft_check_rectangle(char **str);

/**
 * @brief Function to check the map is surrounded by 1s
 * 
 * @param str 
 * @return int 
 */
int		ft_check_walls(char **str, int size_x, int size_y);

/**
 * @brief Function to check if map characters are valid
 * 
 * @param str 
 * @param c 
 * @return int 
 */
int		ft_check_content(char **str, char c);

/**
 * @brief Function to get the map size using rows
 * 
 * @param map 
 * @return int 
 */
int		ft_map_size(char *file);

/**
 * @brief Function to read the map it is given
 * 
 * @param map 
 * @param data 
 */
void	ft_read_map(char *file, t_data *data);

/**
 * @brief Function to get the starting position of the player
 * 
 * @param data 
 */
void	ft_start_pos(t_data *data);

/**
 * @brief Funciton to get the number of collectibles
 * 
 * @param data 
 */
void	ft_get_collectibles(t_data *data);

/**
 * @brief Function to check everything on the map provided
 * 
 * @param file 
 * @return int 
 */
int		ft_map(char *file);

/**
 * @brief Function to check every possible map error
 * 
 * @param data 
 * @return int 
 */
int		ft_valid_map(t_data data);

/**
 * @brief Function to check the characters are correct
 * 
 * @param map 
 * @param size_x 
 * @param size_y 
 * @return int 
 */
int		ft_check_characters(char **map, int size_x, int size_y);

/**
 * @brief Function to free map after floodfill
 * 
 * @param map 
 */
void	ft_freemap(t_data *data);

/**
 * @brief Function that executes every frame
 * 
 * @param param 
 * @return void* 
 */
void	ft_update(void *param);

/**
 * @brief Function to close game window
 * 
 * @param data 
 */
void	ft_close(t_data *data);

/**
 * @brief Function to check if upon touching the exit you have all collectibles
 * 
 * @param data 
 */
void	ft_check_game_status(t_data *data);

/**
 * @brief Function to clean MLX after finishing the game
 * 
 * @param data 
 */
void	ft_terminate(t_data *data);

/**
 * @brief Function to initialize struct 
 * 
 * @param data 
 */
void	ft_init(t_data *data);

/**
 * @brief Function to render the sprite of a given texture
 * 
 * @param i 
 * @param j 
 * @param data 
 * @param texture 
 * @return int 
 */
int		ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture);

/**
 * @brief Function to check exit status
 * 
 * @param data 
 */
void	ft_exit_status(t_data *data);

/**
 * @brief Function to convert textures to images and put them
 * 			in the given array position
 * 
 * @param i 
 * @param j 
 * @param data 
 * @param texture 
 * @return int 
 */
int		ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture);

/**
 * @brief Function to check how many collectibles are left and 
 * 			if the player is in a collectible space
 * 
 * @param data 
 */
void	ft_check_collectibles(t_data *data);

/**
 * @brief Function to fill collectible array
 * 
 * @param data 
 * @param image 
 * @return int 
 */
int		ft_collectible_array(t_data *data, mlx_image_t *image);

/**
 * @brief Function to render all textures
 * 
 * @param data 
 * @return int 
 */
int		ft_render(t_data *data);

/**
 * @brief Function to fill map with textures
 * 
 * @param data 
 * @return int 
 */
int		ft_fill_map(t_data *data);

/**
 * @brief Function to print data
 * 
 * @param data 
 */
void	ft_print_data(t_data *data);

#endif