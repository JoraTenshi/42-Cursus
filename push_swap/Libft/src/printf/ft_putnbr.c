/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:06:20 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/10 09:25:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	ft_putnbr(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
