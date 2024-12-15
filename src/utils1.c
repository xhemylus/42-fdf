/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:49:28 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 01:02:02 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}
	return (str);
}

int	meshalloc(t_mesh *mesh, int edge_count)
{
	mesh->points = malloc(sizeof(t_double3) * mesh->point_count);
	if (mesh->points)
	{
		mesh->pcolor = malloc(sizeof(int) * mesh->point_count);
		if (mesh->pcolor)
		{
			mesh->edge_a = malloc(sizeof(t_double3 *) * (edge_count + 1));
			if (mesh->edge_a)
			{
				mesh->edge_b = malloc(sizeof(t_double3 *) * (edge_count + 1));
				if (mesh->edge_b)
				{
					mesh->ecolor = malloc(sizeof(t_int2 *) * (edge_count));
					if (mesh->ecolor)
						return (1);
					free(mesh->edge_b);
				}
				free(mesh->edge_a);
			}
			free(mesh->pcolor);
		}
		free(mesh->points);
	}
	return (0);
}

void	drawortho(t_mlx *mlx, t_mesh mesh)
{
	int		i;
	t_int2	a;
	t_int2	b;

	i = -1;
	while (mesh.edge_a[++i])
	{
		a.x = nearbyintf(mesh.edge_a[i]->x * mlx->ratio);
		a.y = nearbyintf(-mesh.edge_a[i]->y * mlx->ratio);
		b.x = nearbyintf(mesh.edge_b[i]->x * mlx->ratio);
		b.y = nearbyintf(-mesh.edge_b[i]->y * mlx->ratio);
		drawline(mlx, a, b, mesh.ecolor[i]);
	}
}
