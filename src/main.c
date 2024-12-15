/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:15:47 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 00:53:33 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*map_reader(int fd)
{
	t_list	*map;
	t_list	*node;
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
		return (NULL);
	map = ft_lstnew((void *)temp);
	node = map;
	while (temp != 0)
	{
		temp = get_next_line(fd);
		if (temp)
			node->next = ft_lstnew((void *)temp);
		node = node->next;
	}
	return (map);
}

int	ft_setup(t_mlx *mlx, t_mesh *mesh)
{
	float	temp;
	int		i;
	t_int2	xylen;

	mlx->x = 0;
	mlx->y = 0;
	mlx->r = 0;
	mlx->input.horz = 0;
	mlx->input.vert = 0;
	mlx->input.view = 0;
	mlx->input.rot = 0;
	mlx->input.zoom = 0;
	temp = ft_clamp(POINT_MIN, POINT_MAX, mesh->point_count);
	mlx->dis.x = ft_lerp(DIS_MIN_X, DIS_MAX_X, (temp - POINT_MIN) / POINT_MAX);
	mlx->dis.y = ft_lerp(DIS_MIN_Y, DIS_MAX_Y, (temp - POINT_MIN) / POINT_MAX);
	i = 1;
	xylen.x = mesh->max.x - mesh->min.x;
	xylen.y = fabs(mesh->max.y * 2);
	if (fabs(mesh->min.y) > fabs(mesh->max.y))
		xylen.y = fabs(mesh->min.y * 2);
	while ((xylen.x * i < mlx->dis.x && xylen.y * i < mlx->dis.y) && i <= 75)
		i++;
	return (ft_clamp(1, 75, i - 3));
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_list	*map;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	map = map_reader(fd);
	close(fd);
	if (!map)
		return (1);
	mlx.mesh = meshnew(map);
	if (!mlx.mesh.points)
		return (1);
	mlx.ratio = ft_setup(&mlx, &mlx.mesh);
	mlx.vars.mlx = mlx_init();
	mlx.vars.win = mlx_new_window(mlx.vars.mlx, mlx.dis.x, mlx.dis.y, argv[1]);
	mlx.img.img = mlx_new_image(mlx.vars.mlx, mlx.dis.x, mlx.dis.y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	mlx_loop_hook(mlx.vars.mlx, ft_update, &mlx);
	mlx_hook(mlx.vars.win, 2, 1L << 0, p_hook, &mlx.vars);
	mlx_hook(mlx.vars.win, 3, 1L << 1, r_hook, &mlx.vars);
	mlx_loop(mlx.vars.mlx);
}
