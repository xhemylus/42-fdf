/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:31:07 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 14:35:57 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	if (lst != NULL && f != NULL)
	{
		newlst = ft_lstnew(f(lst->content));
		node = newlst;
		while (lst->next)
		{
			lst = lst->next;
			node->next = ft_lstnew(f(lst->content));
			if (node->next == NULL)
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			node = node->next;
		}
		return (newlst);
	}
	return (NULL);
}
