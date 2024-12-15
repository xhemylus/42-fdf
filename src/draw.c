/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:16:20 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 00:57:13 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpixel(t_mlx mlx, int x, int y, int color)
{
	char	*dst;
	t_data	data;

	x += mlx.dis.x / 2 + mlx.x;
	y += mlx.dis.y / 2 + mlx.y;
	if (x >= mlx.dis.x || y >= mlx.dis.y || x <= 0 || y <= 0)
		return ;
	data = mlx.img;
	dst = data.addr + (y * data.line_length + x
			* (data.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	drawline_x(t_mlx mlx, t_int2 a, t_int2 b, t_int2 s)
{
	int		p;
	t_int2	cur;
	t_int2	pixel;

	p = 2 * (b.y - a.y) - (b.x - a.x);
	cur = a;
	while (cur.x <= b.x)
	{
		pixel = cur;
		if (s.x < 0)
			pixel.x = a.x - (cur.x - a.x);
		if (s.y < 0)
			pixel.y = a.y - (cur.y - a.y);
		ft_putpixel(mlx, pixel.x, pixel.y,
			ft_colorlerp(mlx.color.x, mlx.color.y,
				((float)cur.x - (float)a.x) / ((float)b.x - (float)a.x)));
		cur.x += 1;
		if (p < 0)
			p += 2 * (b.y - a.y);
		else
		{
			p += 2 * (b.y - a.y) - 2 * (b.x - a.x);
			cur.y += 1;
		}
	}
}

void	drawline_y(t_mlx mlx, t_int2 a, t_int2 b, t_int2 s)
{
	int		p;
	t_int2	pixel;
	t_int2	cur;

	p = 2 * (b.x - a.x) - (b.y - a.y);
	cur = a;
	while (cur.y <= b.y)
	{
		pixel = cur;
		if (s.x < 0)
			pixel.x = a.x - (cur.x - a.x);
		if (s.y < 0)
			pixel.y = a.y - (cur.y - a.y);
		ft_putpixel(mlx, pixel.x, pixel.y,
			ft_colorlerp(mlx.color.x, mlx.color.y,
				((float)cur.y - (float)a.y) / ((float)b.y - (float)a.y)));
		cur.y += 1;
		if (p < 0)
			p += 2 * (b.x - a.x);
		else
		{
			p += 2 * (b.x - a.x) - 2 * (b.y - a.y);
			cur.x += 1;
		}
	}
}

void	drawline(t_mlx *mlx, t_int2 a, t_int2 b, t_int2 colors)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	mlx->color.x = colors.x;
	mlx->color.y = colors.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	sx = sign(dx);
	sy = sign(dy);
	if (dx < 0)
		b.x = b.x + 2 * dx * sx;
	if (dy < 0)
		b.y = b.y + 2 * dy * sy;
	if (abs(dx) >= abs(dy))
		drawline_x(*mlx, a, b, ivector2(sx, sy));
	else
		drawline_y(*mlx, a, b, ivector2(sx, sy));
}

void	drawmesh(t_mlx *mlx, t_mesh mesh)
{
	int			i;
	double		k;
	t_double3	r;
	t_int2		a;
	t_int2		b;

	k = atan(0.5);
	i = -1;
	while (mesh.edge_a[++i])
	{
		r.x = mesh.edge_a[i]->x * cos(mlx->r) - mesh.edge_a[i]->z * sin(mlx->r);
		r.z = mesh.edge_a[i]->x * sin(mlx->r) + mesh.edge_a[i]->z * cos(mlx->r);
		a.x = nearbyint((cos(k) * r.x + cos(PI - k)
					* r.z) * mlx->ratio);
		a.y = nearbyint((sin(k) * r.x + sin(PI - k)
					* r.z - mesh.edge_a[i]->y) * mlx->ratio);
		r.x = mesh.edge_b[i]->x * cos(mlx->r) - mesh.edge_b[i]->z * sin(mlx->r);
		r.z = mesh.edge_b[i]->x * sin(mlx->r) + mesh.edge_b[i]->z * cos(mlx->r);
		b.x = nearbyint((cos(k) * r.x + cos(PI - k)
					* r.z) * mlx->ratio);
		b.y = nearbyint((sin(k) * r.x + sin(PI - k)
					* r.z - mesh.edge_b[i]->y) * mlx->ratio);
		if (ft_checkprint(a, b, *mlx))
			drawline(mlx, a, b, mesh.ecolor[i]);
	}
}
