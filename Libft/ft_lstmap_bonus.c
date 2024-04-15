/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:28:17 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/15 21:45:26 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		aux = ft_lstnew((*f)(lst-> content));
		if (!aux)
			ft_lstclear(&aux, del);
		else
			ft_lstadd_back(&map, aux);
		lst = lst -> next;
	}
	return (map);
}
