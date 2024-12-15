/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:12:46 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 15:43:07 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		alloc;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		alloc = ft_strlen(s) - start;
	else
		alloc = len;
	dst = malloc(sizeof(char) * (alloc + 1));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s + start, alloc);
	dst[alloc] = '\0';
	return (dst);
}
