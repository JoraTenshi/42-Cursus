/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:28:17 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/16 10:09:48 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*aux;
	void	*temp;

	if (!lst)
		return (NULL);
	map = NULL;
	temp = map;
	while (lst)
	{
		temp = f(lst-> content);
		aux = ft_lstnew(temp);
		if (!aux)
		{
			del(temp);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, aux);
		lst = lst -> next;
	}
	return (map);
}
