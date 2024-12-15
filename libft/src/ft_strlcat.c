/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:47:27 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 15:20:21 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		destlen;

	i = 0;
	destlen = 0;
	while (dest[destlen] && destlen < size)
		destlen++;
	while (src[i] && (i + destlen + 1 < size))
	{
		dest[i + destlen] = src[i];
		i++;
	}
	if (destlen < size)
		dest[i + destlen] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (destlen + i);
}
