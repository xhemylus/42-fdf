/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:15:35 by abollen           #+#    #+#             */
/*   Updated: 2021/12/19 01:00:20 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.14159265359
# define DIS_MAX_X 1900
# define DIS_MAX_Y 1300
# define DIS_MIN_X 1000
# define DIS_MIN_Y 800
# define POINT_MAX 10000
# define POINT_MIN 4
# define RATIO_MAX 100
# define HEX_BASE "0123456789abcdef"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_input
{
	int	vert;
	int	horz;
	int	zoom;
	int	rot;
	int	view;

}	t_input;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_int2 {
	int	x;
	int	y;
}	t_int2;

typedef struct s_double3 {
	double	x;
	double	y;
	double	z;
}	t_double3;

typedef struct s_mesh {
	int			point_count;
	t_double3	*points;
	int			*pcolor;
	t_double3	**edge_a;
	t_double3	**edge_b;
	t_int2		*ecolor;
	t_double3	max;
	t_double3	min;
}	t_mesh;

typedef struct s_mlx {
	t_vars	vars;
	t_data	img;
	t_data	img2;
	t_int2	dis;
	t_mesh	mesh;
	t_input	input;
	t_int2	color;
	double	r;
	int		x;
	int		y;
	int		ratio;
}	t_mlx;

// DRAW.C
void		ft_putpixel(t_mlx mlx, int x, int y, int color);
void		drawline_x(t_mlx mlx, t_int2 a, t_int2 b, t_int2 s);
void		drawline_y(t_mlx mlx, t_int2 a, t_int2 b, t_int2 s);
void		drawline(t_mlx *mlx, t_int2 a, t_int2 b, t_int2 colors);
void		drawmesh(t_mlx *mlx, t_mesh mesh);

// UTILS.C
t_double3	new_vector3(double x, double y, double z);
t_int2		ivector2(int x, int y);
int			ft_lerp(int a, int b, float t);
double		ft_clamp(int min, int max, int n);
int			ft_checkprint(t_int2 a, t_int2 b, t_mlx mlx);

// UTILS1.C
int			ft_close(t_mlx *mlx);
int			ft_isbase(char c, char *base);
char		*ft_strlowcase(char *str);
int			meshalloc(t_mesh *mesh, int edge_count);
void		drawortho(t_mlx *mlx, t_mesh mesh);

// MAP.C
int			charskip(char *str, int option);
t_int2		mapmax(t_list *map);
void		ft_clear_img(t_mlx mlx);
int			ft_update(t_mlx *mlx);

// MESH.C
void		pointnew(t_list *map, t_mesh *mesh, t_int2 max);
void		pointassignation(t_mesh *mesh, int a, int b, int i);
void		edgenew(t_mesh *mesh, t_int2 max);
void		getlimits(t_mesh *mesh);
t_mesh		meshnew(t_list *map);

// GNL.C - GNL_U.C
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*gnl_strjoin(char *s1, char const *s2);
char		*ft_strdup(const char *src);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);

// INPUT.C
int			p_hook(int keycode, t_mlx *mlx);
int			r_hook(int keycode, t_mlx *mlx);
int			ft_close(t_mlx *mlx);
int			sign(int x);
void		ft_input(t_mlx *mlx);

// COLORS.C
int			rainbow_color(double index, int range);
void		color_fill(t_mesh *mesh);
int			ft_colorlerp(int a, int b, float t);
int			color_gen(char *str);
int			ft_atoi_base(char *str, char *base);

int			ft_wordcount(char const *s, char c);

#endif