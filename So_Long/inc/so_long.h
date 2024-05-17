/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:58:41 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/17 12:46:32 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 256
# define HEIGHT 256

# include "Libft/inc/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t	*mlx;
	char	**map;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	int		moves;
	int		p_collectibles;
	int		t_collectibles;
}	t_data;

/**
 * @brief Function to check if the provided map is a rectangle
 * 
 * @param str 
 * @return int 
 */
int	ft_check_rectangle(char **str);

/**
 * @brief Function to check the map is surrounded by 1s
 * 
 * @param str 
 * @return int 
 */
int	ft_check_walls(char **str);

/**
 * @brief Function to check if map characters are valid
 * 
 * @param str 
 * @param c 
 * @return int 
 */
int	ft_check_content(char **str, char c);

#endif