/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:51:00 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/19 12:54:38 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_disable(t_anim *anim)
{
	anim->up->enabled = 0;
	anim->down->enabled = 0;
	anim->left->enabled = 0;
	anim->right->enabled = 0;
}

void	ft_anim_vertical(t_anim	*anim, char direction)
{
	if (direction == 'W')
	{
		anim->up->instances[0].y -= 64;
		anim->down->instances[0].y -= 64;
		anim->left->instances[0].y -= 64;
		anim->right->instances[0].y -= 64;
		anim->up->enabled = 1;
	}
	else if (direction == 'S')
	{
		anim->up->instances[0].y += 64;
		anim->down->instances[0].y += 64;
		anim->left->instances[0].y += 64;
		anim->right->instances[0].y += 64;
		anim->down->enabled = 1;
	}
}

void	ft_anim_horizontal(t_anim *anim, char direction)
{
	if (direction == 'A')
	{
		anim->up->instances[0].x -= 64;
		anim->down->instances[0].x -= 64;
		anim->left->instances[0].x -= 64;
		anim->right->instances[0].x -= 64;
		anim->left->enabled = 1;
	}
	else if (direction == 'D')
	{
		anim->up->instances[0].x += 64;
		anim->down->instances[0].x += 64;
		anim->left->instances[0].x += 64;
		anim->right->instances[0].x += 64;
		anim->right->enabled = 1;
	}
}

void	ft_animation(t_anim *anim, char direction)
{
	ft_disable(anim);
	ft_anim_vertical(anim, direction);
	ft_anim_horizontal(anim, direction);
}
