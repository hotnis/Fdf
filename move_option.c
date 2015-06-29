/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 08:42:57 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 14:37:19 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image_up(t_env *e)
{
	e->move_y -= 10;
	erase(e);
}

void	move_image_down(t_env *e)
{
	e->move_y += 10;
	erase(e);
}

void	move_image_left(t_env *e)
{
	e->move_x -= 10;
	erase(e);
}

void	move_image_right(t_env *e)
{
	e->move_x += 10;
	erase(e);
}
