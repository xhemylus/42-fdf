/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:13:07 by abollen           #+#    #+#             */
/*   Updated: 2021/12/08 17:13:56 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = -1;
	while (++i < len)
		ptr[i] = c;
	return (b);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		len;

	i = -1;
	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i])
			dst[i] = s1[i];
	i = -1;
	while (s2[++i])
		dst[i + ft_strlen(s1)] = s2[i];
	dst[i + ft_strlen(s1)] = '\0';
	if (s1)
		free(s1);
	return (dst);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
