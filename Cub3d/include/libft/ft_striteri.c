/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:54:17 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/25 17:35:10 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*aux;

	if (!s || !f)
		return ;
	i = 0;
	aux = s;
	while (s[i])
	{
		f(i, &aux[i]);
		i++;
	}
}

/* void	ft_toupper2(unsigned int n, char *c)
{
	n=0;
	c[0] = ft_toupper(c[0]);
}

#include <stdio.h>

int main(void)
{
	char s[] = "Pipo es un buen perro";

	ft_striteri(s, ft_toupper2);
	printf("%s", s);
	return (0);
} */