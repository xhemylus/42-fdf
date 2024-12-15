/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:48:46 by abollen           #+#    #+#             */
/*   Updated: 2021/12/18 23:11:15 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double3	new_vector3(double x, double y, double z)
{
	t_double3	vector3;

	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return (vector3);
}

t_int2	ivector2(int x, int y)
{
	t_int2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

int	ft_lerp(int a, int b, float t)
{
	return (a + (b - a) * t);
}

double	ft_clamp(int min, int max, int n)
{
	if (n <= min)
		return (min);
	else if (n >= max)
		return (max);
	else
		return (n);
}

int	ft_checkprint(t_int2 a, t_int2 b, t_mlx mlx)
{
	t_int2	mid;

	mid.x = mlx.dis.x / 2;
	mid.y = mlx.dis.y / 2;
	if (a.x <= mid.x - mlx.x && a.x >= -mid.x - mlx.x)
		if (a.y <= mid.y - mlx.y && a.y >= -mid.y - mlx.y)
			return (1);
	if (b.x <= mid.x - mlx.x && b.x >= -mid.x - mlx.x)
		if (b.y <= mid.y - mlx.y && b.y >= -mid.y - mlx.y)
			return (1);
	return (0);
}
