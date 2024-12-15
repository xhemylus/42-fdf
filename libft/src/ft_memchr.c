/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:58:29 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 14:01:04 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = -1;
	s = (unsigned char *)src;
	while (++i < len)
		if (s[i] == (unsigned char )c)
			return (&s[i]);
	return (0);
}
