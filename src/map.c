/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:46:31 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 00:48:56 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	charskip(char *str, int option)
{
	int	i;

	i = 0;
	if (option == 0)
	{
		while (!ft_isdigit(str[i]) && str[i] != '-')
			i++;
	}
	else if (option == 1)
	{
		while (ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
	else if (option == 2)
	{
		if (str[0] == '0' || str[i] == ',')
			i += 3;
		while (ft_isbase(str[i], HEX_BASE) >= 0 || str[i] == ',')
			i++;
	}
	return (i);
}

t_int2	mapmax(t_list *map)
{
	t_int2	max;

	max.x = ft_wordcount(map->content, ' ');
	max.y = ft_lstsize(map);
	return (max);
}

void	ft_clear_img(t_mlx mlx)
{
	int		i;
	char	*dst;

	i = -1;
	dst = (char *)mlx.img.addr;
	while (++i < mlx.dis.y * mlx.img.line_length)
		dst[i] = 0;
}

int	ft_update(t_mlx *mlx)
{
	ft_input(mlx);
	ft_clear_img(*mlx);
	if (mlx->input.view == 0)
		drawmesh(mlx, mlx->mesh);
	else
		drawortho(mlx, mlx->mesh);
	mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img.img, 0, 0);
	return (1);
}
