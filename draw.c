/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 07:13:46 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:15:01 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_env *e)
{
	int i;
	int j;

	j = 0;
	while (j < e->map_y && j < WIN_H)
	{
		i = 0;
		while (i < e->map_x && i < WIN_W)
		{
			if (i < e->map_x - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j][i + 1]));
			if (j < e->map_y - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j + 1][i]));
			i++;
		}
		j++;
	}
}

void		draw_line(t_env *e, t_point *point1, t_point *point2)
{
	t_point pt;
	int		e2;
	t_bres	*bres;

	bres = bres_construct(point1, point2, (e->max_z));
	pt.x = point1->tx;
	pt.y = point1->ty;
	while (1)
	{
		if ((check_x(e, pt.x) && check_y(e, pt.y)))
			draw_point(e, create_x(e, pt.x), create_y(e, pt.y), point1->color);
		if (pt.x == point2->tx && pt.y == point2->ty)
			break ;
		if ((e2 = bres->delta_error) > -(bres->delta_x))
		{
			bres->delta_error -= bres->delta_y;
			pt.x += bres->sign_x;
		}
		if (e2 < bres->delta_y)
		{
			bres->delta_error += bres->delta_x;
			pt.y += bres->sign_y;
		}
	}
	free(bres);
}

void		draw_point(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->data[(x * 4) + (y * e->sizeline)], &(color),
		(size_t)(sizeof(int)));
}

int			choose_color(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (WHITE);
	else if (((p1 + p2) / 2) == 0)
		return (BROWN);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE);
	else
		return (GREEN);
}

t_bres		*bres_construct(t_point *point1, t_point *point2, int max)
{
	t_bres *bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->delta_x = ft_abs(point2->tx - point1->tx);
	bres->sign_x = point1->tx < point2->tx ? 1 : -1;
	bres->delta_y = ft_abs(point2->ty - point1->ty);
	bres->sign_y = point1->ty < point2->ty ? 1 : -1;
	bres->delta_error = (bres->delta_x > bres->delta_y ? bres->delta_x :
		-(bres->delta_y)) / 2;
	point1->color = choose_color(point1->z, point2->z, max);
	return (bres);
}
