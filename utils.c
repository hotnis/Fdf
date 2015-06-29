/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 07:12:44 by mzane             #+#    #+#             */
/*   Updated: 2015/05/05 18:27:12 by mzane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erase(t_env *e)
{
	ft_bzero(e->data, WIN_W * WIN_H * 4);
	expose_hook(e);
}

int		len_tab(char *argv)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Fdf");
		exit(1);
	}
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		if (ret == -1)
		{
			perror("Fdf");
			exit(1);
		}
		size += ret;
	}
	close(fd);
	free(buff);
	return (size);
}

int		count_map_length(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		sq(int x)
{
	return (x * x);
}

void	default_mode(t_env *e)
{
	e->pad = 20;
	e->pad_h = 5;
	e->move_x = 1;
	e->move_y = 1;
	e->angle = 0;
	erase(e);
}
