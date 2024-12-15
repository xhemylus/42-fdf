/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:34:56 by abollen           #+#    #+#             */
/*   Updated: 2022/01/15 10:29:51 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->vars.mlx, mlx->vars.win);
	free(mlx->mesh.points);
	free(mlx->mesh.edge_a);
	free(mlx->mesh.edge_b);
	exit(0);
}

void	ft_input(t_mlx *mlx)
{
	mlx->ratio += mlx->input.zoom;
	if (mlx->ratio < 0)
		mlx->ratio = 0;
	if (mlx->ratio > RATIO_MAX)
		mlx->ratio = RATIO_MAX;
	mlx->x += mlx->input.horz * 10;
	mlx->y += mlx->input.vert * 10;
	mlx->r += mlx->input.rot * 0.01;
}

int	p_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		mlx->input.vert = -1;
	if (keycode == 125)
		mlx->input.vert = 1;
	if (keycode == 124)
		mlx->input.horz = 1;
	if (keycode == 123)
		mlx->input.horz = -1;
	if (keycode == 0)
		mlx->input.rot = 1;
	if (keycode == 2)
		mlx->input.rot = -1;
	if (keycode == 69)
		mlx->input.zoom = 1;
	if (keycode == 78)
		mlx->input.zoom = -1;
	if (keycode == 9)
		mlx->input.view = 1;
	if (keycode == 53)
		ft_close(mlx);
	return (0);
}

int	r_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		mlx->input.vert = 0;
	if (keycode == 125)
		mlx->input.vert = 0;
	if (keycode == 124)
		mlx->input.horz = 0;
	if (keycode == 123)
		mlx->input.horz = 0;
	if (keycode == 0)
		mlx->input.rot = 0;
	if (keycode == 2)
		mlx->input.rot = 0;
	if (keycode == 69)
		mlx->input.zoom = 0;
	if (keycode == 78)
		mlx->input.zoom = 0;
	if (keycode == 9)
		mlx->input.view = 0;
	if (keycode == 53)
		ft_close(mlx);
	return (0);
}

int	sign(int x)
{
	return ((x > 0) - (x < 0));
}
