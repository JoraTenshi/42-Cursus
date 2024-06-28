/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:10:11 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/10 09:25:54 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf/ft_printf.h"

int	ft_putunbr(int nb)
{
	char	*str;
	int		len;

	str = ft_utoa(nb);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
