/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 02:19:40 by abollen           #+#    #+#             */
/*   Updated: 2022/01/19 20:18:46 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(int c, char **dst)
{
	int	i;

	i = -1;
	while (++i < c)
		free(dst[i]);
	free(dst);
	return (NULL);
}

int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	isword;

	i = -1;
	count = 0;
	isword = 0;
	while (s[++i])
	{
		if (isword && s[i] == c)
			isword = 0;
		else if (!isword && s[i] != c)
		{
			count++;
			isword = 1;
		}
	}
	return (count);
}

static char	**ft_dispatch(char const *s, char c, char **dst)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = -1;
			dst[++j] = malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1));
			if (!dst[j])
				return (ft_free(j, dst));
			while (s[i] && s[i] != c)
				dst[j][++k] = s[i++];
			dst[j][++k] = '\0';
		}
	}
	dst[j + 1] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**destarray;

	if (!s)
		return (NULL);
	destarray = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!destarray)
		return (NULL);
	destarray = ft_dispatch(s, c, destarray);
	if (!destarray)
		return (NULL);
	return (destarray);
}
