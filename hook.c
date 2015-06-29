/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 07:13:23 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:44:10 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		expose_hook(t_env *e)
{
	calcule_coord(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_info_to_windows(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 69)
		zoom_map(e);
	if (keycode == 78)
		de_zoom_map(e);
	if (keycode == 126)
		move_image_up(e);
	if (keycode == 125)
		move_image_down(e);
	if (keycode == 123)
		move_image_left(e);
	if (keycode == 124)
		move_image_right(e);
	if (keycode == 75)
		rotation_left(e);
	if (keycode == 67)
		rotation_right(e);
	if (keycode == 31)
		default_mode(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		increase_pike(e);
	if (button == 2)
		decrease_pike(e);
	(void)x;
	(void)y;
	return (0);
}
