/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:22:06 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 12:10:35 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;
	char	*lasts;
	char	*lastd;

	i = -1;
	d = dst;
	s = src;
	lasts = s + (n - 1);
	lastd = d + (n - 1);
	if (!dst && !src && n)
		return (0);
	if (d < s)
	{
		while (++i < n)
			d[i] = s[i];
	}
	else
	{
		while (++i < n)
			lastd[-i] = lasts[-i];
	}
	return (dst);
}
