/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:59:15 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 12:10:29 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (!new || !alst)
		return ;
	else if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		node = *alst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
