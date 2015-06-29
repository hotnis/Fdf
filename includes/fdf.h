/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 07:15:33 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:44:20 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define WIN_H 1200
# define WIN_W 1900

# define BLUE 0x0041FF
# define BROWN 0xAD4F09
# define GREEN 0x25FF50
# define WHITE 0xFFFFFF

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			tx;
	int			ty;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*data;
	void		*img;
	int			sizeline;
	int			endian;
	int			bpp;
	t_point		**map;
	char		*path;
	float		angle;
	int			map_x;
	int			map_y;
	int			max_z;
	int			pad;
	int			move_x;
	int			move_y;
	int			pad_h;
}				t_env;

typedef struct	s_bresenham
{
	int			delta_x;
	int			sign_x;
	int			delta_y;
	int			sign_y;
	int			delta_error;
}				t_bres;

int				count_map_length(char **str);
int				len_tab(char *argv);
t_point			*create_int_table(t_env *e, char *str, int pos);
t_point			**create_map(t_env *e);
t_point			ft_create_point(char *str, int x, int y);
void			ft_import_map(t_env *e);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
void			calcule_coord(t_env *e);
void			calculate(t_env *e, t_point *point);
int				choose_color(int p1, int p2, int max);
void			draw_map(t_env *e);
void			draw_line(t_env *e, t_point *point1, t_point *point2);
t_bres			*bres_construct(t_point *point1, t_point *point2, int max);
void			draw_point(t_env *e, int x, int y, int color);
int				check_x(t_env *e, int x);
int				check_y(t_env *e, int y);
int				create_x(t_env *e, int x);
int				create_y(t_env *e, int y);
int				sq(int x);
void			calcule_rotation(t_env *e, t_point *point);
int				mouse_hook(int button, int x, int y, t_env *e);
void			increase_pike(t_env *e);
void			decrease_pike(t_env *e);
void			zoom_map(t_env *e);
void			de_zoom_map(t_env *e);
void			move_image_up(t_env *e);
void			move_image_down(t_env *e);
void			move_image_left(t_env *e);
void			move_image_right(t_env *e);
void			rotation_right(t_env *e);
void			rotation_left(t_env *e);
void			erase(t_env *e);
void			put_info_to_windows(t_env *e);
void			put_meta(t_env *e);
void			put_black_screen(t_env *e);
void			default_mode(t_env *e);
int				free_tab(char **tab_2d);

#endif
