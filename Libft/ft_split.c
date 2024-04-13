/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:04:39 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/13 11:04:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] != c)
		{
			while (str[a] != c && str[a])
				a++;
			count++;
		}
		else
			a++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int	i;

	i = 0;
}
