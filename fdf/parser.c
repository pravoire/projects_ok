/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:36:05 by pravoire          #+#    #+#             */
/*   Updated: 2016/10/10 19:00:53 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			extract_pts(t_env *e, char *s, int off)
{
	char			**buf;
	int				i;

	buf = ft_strsplit(s, ' ');
	i = 0;
	while (i < e->map_w)
	{
		e->map[off][i].z = ft_atoi(buf[i]);
		i++;
		if (e->map[off][i].z > e->z_max)
			e->z_max = e->map[off][i].z;
		else if (e->map[off][i].z < e->z_min)
			e->z_min = e->map[off][i].z;
	}
}

void				get_map_pts(t_env *e, char *s)
{
	int				fd;
	int				tmp;
	char			*line;
	int				i;

	line = NULL;
	while ((fd = open(s, O_RDONLY)) > 1023)
		close(fd);
	if (fd <= -1)
		error(4);
	i = 0;
	while ((tmp = get_next_line(fd, &line)))
	{
		extract_pts(e, line, i);
		i++;
		free(line);
	}
	if (tmp == -1)
		error(4);
}

void				get_map_size(t_env *e, char *s)
{
	int				n;
	int				fd;
	int				tmp;
	char			*line;

	line = NULL;
	while ((fd = open(s, O_RDONLY)) > 1023)
		close(fd);
	if (fd <= -1)
		error(4);
	while ((tmp = get_next_line(fd, &line)))
	{
		n = ft_strtablen(ft_strsplit(line, ' '));
		if (e->map_w != -1 && n != e->map_w)
			error(6);
		if (n > e->map_w)
			e->map_w = n;
		e->map_h++;
		free(line);
	}
	if (tmp == -1)
		error(4);
}
