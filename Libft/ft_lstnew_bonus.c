/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:14:24 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/16 09:15:14 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_list;

	n_list = malloc(sizeof(t_list));
	if (!n_list)
		return (NULL);
	n_list -> content = content;
	n_list -> next = NULL;
	return (n_list);
}
