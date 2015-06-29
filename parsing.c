/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 07:12:13 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:42:13 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

int			count_map_height(t_point **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
		i++;
	return (i);
}

int			search_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_point		**create_map(t_env *e)
{
	t_point	**grid;
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	e->map_x = 0;
	grid = (t_point **)malloc(sizeof(t_point *) * len_tab(e->path));
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &temp) == 1)
	{
		grid[i] = create_int_table(e, temp, i);
		free(temp);
		i++;
	}
	grid[i] = create_int_table(e, temp, i);
	free(temp);
	close(fd);
	e->map_y = count_map_height(grid);
	return (grid);
}

t_point		*create_int_table(t_env *e, char *str, int pos)
{
	t_point	*list;
	char	**split;
	int		i;
	int		size;

	i = -1;
	if (search_number(str))
		return (NULL);
	split = ft_strsplit(str, ' ');
	size = count_map_length(split);
	e->map_x = (size > e->map_x) ? size : e->map_x;
	list = (t_point *)malloc(sizeof(t_point) * (e->map_x + 1));
	while (split[++i] != NULL)
	{
		e->max_z = ((ft_atoi(split[i])) > e->max_z) ? ft_atoi(split[i])
			: e->max_z;
		list[i] = ft_create_point(split[i], i, pos);
		free(split[i]);
	}
	while (++i < e->map_x)
	{
		list[i] = ft_create_point("0", i, pos);
	}
	free(split);
	return (list);
}

t_point		ft_create_point(char *str, int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	return (point);
}
