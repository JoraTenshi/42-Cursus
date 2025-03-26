/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:18 by aarenas-          #+#    #+#             */
/*   Updated: 2024/04/17 14:50:42 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	aux = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp)
		{
			ft_lstadd_back(&aux, tmp);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&aux, del);
			return (0);
		}
	}
	return (aux);
}
