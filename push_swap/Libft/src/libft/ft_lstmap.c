/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:28:17 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/09 11:47:25 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*aux;

	if (!lst)
		return (NULL);
	map = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst-> content));
		if (!aux)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, aux);
		lst = lst -> next;
	}
	return (map);
}
