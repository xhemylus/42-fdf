/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:07:19 by vpericat          #+#    #+#             */
/*   Updated: 2021/12/15 15:22:02 by abollen          ###   ########.fr       */
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

	i = -1;
	ptr = b;
	while (++i < len)
		ptr[i] = c;
	return (b);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*dest;
	int		len;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i])
			dest[i] = s1[i];
	i = -1;
	while (s2[++i])
		dest[i + ft_strlen(s1)] = s2[i];
	dest[i + ft_strlen(s1)] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (--i >= 0)
		dest[i] = src[i];
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
