/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:05:04 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 01:10:34 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rainbow_color(double index, int range)
{
	double	hue;
	double	n;
	int		nmod;

	hue = 3600;
	if (index >= 0)
	{
		n = index * ((hue - 1) / range);
		nmod = ((int)n % ((int)hue / 4)) * (255 / (hue / 4));
		if (n >= 0 && n < hue / 4)
			return (0 << 24 | 0 | (nmod) << 8 | 255);
		else if (n >= hue / 4 && n < hue / 4 * 2)
			return (0 << 24 | 0 << 16 | 255 << 8 | (255 - nmod));
		else if (n >= hue / 4 * 2 && n < hue / 4 * 3)
			return (0 << 24 | (nmod) << 16 | 255 << 8 | 0);
		else if (n >= hue / 4 * 3 && n < hue / 4 * 4)
			return (0 << 24 | 255 << 16 | (255 - nmod) << 8 | 0);
	}
	return (0xFFFFFF);
}

void	color_fill(t_mesh *mesh)
{
	int	max;
	int	min;
	int	i;

	max = 0;
	min = 0;
	i = -1;
	while (++i < mesh->point_count)
	{
		if (mesh->points[i].y > max)
			max = mesh->points[i].y;
		if (mesh->points[i].y < min)
			min = mesh->points[i].y;
	}
	i = -1;
	while (++i < mesh->point_count)
	{
		if (mesh->pcolor[i] == -1)
			mesh->pcolor[i] = \
				rainbow_color(mesh->points[i].y - min, max - min);
	}
}

int	ft_colorlerp(int a, int b, float t)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = ft_lerp(a >> 16 & (0xFF), b >> 16 & (0xFF), t);
	green = ft_lerp(a >> 8 & (0xFF), b >> 8 & (0xFF), t);
	blue = ft_lerp(a & (0xFF), b & (0xFF), t);
	alpha = ft_lerp(a >> 24 & (0xFF), b >> 24 & (0xFF), t);
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

int	color_gen(char *str)
{
	if (*str == ',')
		return (ft_atoi_base(str, HEX_BASE));
	else
		return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long	anum;
	int		i;

	anum = 0;
	i = 3;
	while (ft_isbase(str[i], base) >= 0)
	{
		anum = anum * 16;
		anum = anum + ft_isbase(str[i], base);
		i++;
	}
	return (anum);
}
