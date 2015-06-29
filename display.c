/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 01:15:10 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:44:02 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	put_info_to_windows(t_env *e)
{
	put_meta(e);
}

void	put_meta(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 1500, 100, 0xFFFFFF, "Legend :");
	mlx_string_put(e->mlx, e->win, 1500, 150, 0xFFFFFF, "move : arrow key");
	mlx_string_put(e->mlx, e->win, 1500, 170, 0xFFFFFF, "zoom : + , -");
	mlx_string_put(e->mlx, e->win, 1500, 190, 0xFFFFFF, "rotation : / , *");
	mlx_string_put(e->mlx, e->win, 1500, 210, 0xFFFFFF,
			"change Z : mouse 1 , mouse 3");
	mlx_string_put(e->mlx, e->win, 1500, 230, 0xFFFFFF,
			"valeur par defaut : o");
}
