/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:15:55 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 01:20:23 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pointnew(t_list *map, t_mesh *mesh, t_int2 max)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = -1;
	j = -1;
	while (++y < max.y)
	{
		ft_strlowcase((char *)map->content);
		i = 0;
		x = -1;
		while (++x < max.x)
		{
			j++;
			i += charskip(&map->content[i], 0);
			mesh->points[j].x = x - ((float)max.x - 1) / 2;
			mesh->points[j].y = ft_atoi((char *)&map->content[i]);
			mesh->points[j].z = y - ((float)max.y - 1) / 2;
			i += charskip(&map->content[i], 1);
			mesh->pcolor[j] = color_gen((char *)&map->content[i]);
			i += charskip(&map->content[i], 2);
		}
		map = map->next;
	}
}

void	pointassignation(t_mesh *mesh, int a, int b, int i)
{
	mesh->edge_a[i] = &mesh->points[a];
	mesh->edge_b[i] = &mesh->points[b];
	mesh->ecolor[i].x = mesh->pcolor[a];
	mesh->ecolor[i].y = mesh->pcolor[b];
}

void	edgenew(t_mesh *mesh, t_int2 max)
{
	int	i;
	int	x;
	int	y;

	y = -1;
	i = -1;
	while (++y < max.y)
	{
		x = -1;
		while (++x < max.x)
		{
			if (x < max.x - 1)
			{
				i++;
				pointassignation(mesh, y * (int)max.x + x,
					y * (int)max.x + x + 1, i);
			}
			if (y < max.y - 1)
			{
				i++;
				pointassignation(mesh, y * (int)max.x + x,
					(y + 1) * (int)max.x + x, i);
			}
		}
	}
}

void	getlimits(t_mesh *mesh)
{
	int		i;
	double	temp;
	double	k;

	i = -1;
	mesh->max.x = 0;
	mesh->max.y = 0;
	mesh->min.x = 0;
	mesh->min.y = 0;
	k = atan(0.5);
	while (++i < mesh->point_count)
	{
		temp = (cos(k) * mesh->points[i].x + cos(PI - k)
				* mesh->points[i].z);
		if (temp > mesh->max.x)
			mesh->max.x = temp;
		if (temp < mesh->min.x)
			mesh->min.x = temp;
		temp = (sin(k) * mesh->points[i].x + sin(PI - k)
				* mesh->points[i].z - mesh->points[i].y);
		if (temp > mesh->max.y)
			mesh->max.y = temp;
		if (temp < mesh->min.y)
			mesh->min.y = temp;
	}
}

t_mesh	meshnew(t_list *map)
{
	t_mesh	mesh;
	t_int2	max;
	int		edge_count;

	max = mapmax(map);
	mesh.point_count = max.x * max.y;
	edge_count = 2 * mesh.point_count - max.x - max.y;
	if (!meshalloc(&mesh, edge_count))
	{
		ft_lstclear(&map, &free);
		mesh.points = NULL;
		return (mesh);
	}
	mesh.edge_a[edge_count] = NULL;
	mesh.edge_b[edge_count] = NULL;
	pointnew(map, &mesh, max);
	color_fill(&mesh);
	getlimits(&mesh);
	edgenew(&mesh, max);
	return (mesh);
}
