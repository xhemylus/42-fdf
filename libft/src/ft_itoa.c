/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:17:14 by abollen           #+#    #+#             */
/*   Updated: 2021/11/05 12:10:29 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstring(char *str, int len)
{
	int		i;
	char	temp;

	i = -1;
	while (++i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return (str);
}

static int	ft_intlen(long int temp)
{
	int	len;

	if (temp == 0)
		return (1);
	len = 0;
	if (temp < 0)
	{
		len++;
		temp *= -1;
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	long int		temp;
	int				len;
	char			*dst;

	i = -1;
	temp = n;
	len = ft_intlen(temp);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (temp < 0)
		temp = temp * -1;
	if (temp == 0)
		dst[++i] = '0';
	while (temp > 0)
	{
		dst[++i] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		dst[++i] = '-';
	dst[++i] = '\0';
	return (ft_revstring(dst, len));
}
