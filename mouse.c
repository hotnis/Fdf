/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 23:12:51 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 12:26:02 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		increase_pike(t_env *e)
{
	e->pad_h = (e->pad_h + 1.2 <= 0) ? e->pad_h : e->pad_h + 1.2;
	erase(e);
}

void		decrease_pike(t_env *e)
{
	e->pad_h = (e->pad_h - 1.2 <= 0) ? e->pad_h : e->pad_h - 1.2;
	erase(e);
}

void		rotation_left(t_env *e)
{
	e->angle -= 0.05;
	erase(e);
}

void		rotation_right(t_env *e)
{
	e->angle += 0.05;
	erase(e);
}
