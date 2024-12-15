/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:43:13 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 12:13:05 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char const *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	char const	*start;
	char		*dst;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_ischarset(set, s1[i]))
		i++;
	start = &s1[i];
	i = 0;
	while (start[i])
		i++;
	i--;
	while (i > 0 && ft_ischarset(set, start[i]))
		i--;
	dst = malloc(sizeof(char) * (i + 2));
	if (!dst)
		return (NULL);
	dst[++i] = '\0';
	while (--i >= 0)
		dst[i] = start[i];
	return (dst);
}
