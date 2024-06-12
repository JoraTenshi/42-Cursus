/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:51:00 by jcallejo          #+#    #+#             */
/*   Updated: 2024/06/12 11:19:18 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_anim_init(t_anim *anim)
{
	anim->up = NULL;
	anim->down = NULL;
	anim->left = NULL;
	anim->right = NULL;
}

void	ft_disable(t_anim *anim)
{
	anim->up->enabled = 0;
	anim->down->enabled = 0;
	anim->left->enabled = 0;
	anim->right->enabled = 0;
}

void	ft_anim_vertical(t_anim	*anim, char direction)
{
	ft_disable(anim);
	if (direction == 'W')
	{
		anim->up->instances[0].y -= 64;
		anim->down->instances[0].y -= 64;
		anim->left->instances[0].y -= 64;
		anim->right->instances[0].y -= 64;
	}
	else if (direction == 'S')
	{
		anim->up->instances[0].y += 64;
		anim->down->instances[0].y += 64;
		anim->left->instances[0].y += 64;
		anim->right->instances[0].y += 64;
	}
}

void	ft_anim_horizontal(t_anim *anim, char direction)
{
	ft_disable(anim);
	if (direction == 'A')
	{
		anim->up->instances[0].y -= 64;
		anim->down->instances[0].y -= 64;
		anim->left->instances[0].y -= 64;
		anim->right->instances[0].y -= 64;
	}
	else if (direction == 'D')
	{
		anim->up->instances[0].y += 64;
		anim->down->instances[0].y += 64;
		anim->left->instances[0].y += 64;
		anim->right->instances[0].y += 64;
	}
}

void	ft_animation(t_anim *anim, char direction)
{
	ft_anim_init(anim);
	ft_disable(anim);
	ft_anim_vertical(anim, direction);
	ft_anim_horizontal(anim, direction);
}
